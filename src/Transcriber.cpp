#include"Transcriber.hpp"
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<filesystem>
#include<algorithm>
#include<vector>

constexpr const char* kModel = "mlx-community/whisper-large-v3-turbo";

 
void Transcriber::split(VideoJob& job) {                        
    std::filesystem::create_directories(job.getJobDir()/"chunks");

    std::string command = "ffmpeg ";
    command += "-hide_banner ";
    command += "-loglevel error ";
    auto audioDir = job.getJobDir() / "audio.opus";
    command += "-i \"";
    command += audioDir.string();
    command += "\" ";
    command += "-f segment ";
    command += "-segment_time ";
    command += std::to_string(chunkTime);
    command += " -c copy ";
    auto chunksDir = job.getJobDir() / "chunks" / "%03d.opus"    ;
    command += "\"";
    command += chunksDir.string();
    command += "\" ";
    command += "-y";

    std::cout << command << '\n';
    std::system(command.c_str());
}


void Transcriber::transcribeChunks(VideoJob& job) {
    namespace fs = std::filesystem;

    for (const auto& entry : fs::directory_iterator(job.getJobDir() / "chunks")) {
        if (entry.path().extension() != ".opus")
            continue;
        std::string name = entry.path().stem().string();
        auto txtPath = entry.path().parent_path() / (name + ".txt");
        if (fs::exists(txtPath))
            continue;

    std::string command = "mlx_whisper ";
    command += "\"";
    command += entry.path().string();
    command += "\" ";
    command += "--model ";
    command += kModel;
    command += " ";
    command += "--output-dir \"";
    command += entry.path().parent_path().string();
    command += "\" ";
    command += "--output-name ";
    command += name;
    command += " ";
    command += "--output-format txt ";
    command += "--best-of 3 ";
    command += "--language ru ";
    command += "--condition-on-previous-text False";

    std::cout << command << '\n';
    std::system(command.c_str());
    }
}

void Transcriber::merge(VideoJob& job) {
    namespace fs = std::filesystem;

    auto output = job.getJobDir() / "text.txt";
    std::ofstream result(output);
    if (!result) {
        std::cerr << "Can't create " << output << '\n';
        return;
    }

    std::vector<fs::path> files;

    for (const auto& entry : fs::directory_iterator(job.getJobDir() / "chunks"))
    {
        if (entry.path().extension() == ".txt")
            files.push_back(entry.path());
    }

    std::sort(files.begin(), files.end());

    for (const auto& file : files) {
    std::ifstream input(file);

    result << input.rdbuf();
    result << "\n\n";
    }
}

void Transcriber::cleanup(VideoJob& job) {
    std::string command = "rm -f \"";
    auto dirPathAudio = job.getJobDir() / "audio.opus";
    auto dirPathChunks = job.getJobDir() / "chunks";

    command += dirPathAudio.string();
    command += "\" ";
    command += "rm -rf \"";
    command += dirPathChunks.string();
    command += "\"";

    std::cout << command << '\n';
    std::system(command.c_str());
}
    

void Transcriber::transcribe(VideoJob& job) {
    split(job);
    transcribeChunks(job);
    merge(job);
}


