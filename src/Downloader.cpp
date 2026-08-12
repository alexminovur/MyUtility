#include"Downloader.hpp"
#include"VideoJob.hpp"
#include<string>
#include<cstdlib>

constexpr const char* kCookies = "chrome";

void Downloader::download (VideoJob& job) {
    std::filesystem::create_directories(job.getJobDir());

    if (std::filesystem::exists(job.getJobDir() / "video.mp4")) {
        std::cout << "Already downloaded!" << '\n';
        return;
    }
    int bestQuality = 0;

    std::cout << "Download in best quality? (1 - yes, 0 - no): ";
    std::cin >> bestQuality;
    std::string format = "bv*[height<=720][vcodec^=avc1]+ba[acodec^=mp4a]/b";;
    if (bestQuality) {
        format = "bestvideo+bestaudio/best";
    }

    std::string command = "yt-dlp ";
    command += "--cookies-from-browser ";
    command += kCookies;
    command += " ";
    command += "--quiet ";
    command += "-f \"";
    command += format;
    command += "\" ";
    command += "--merge-output-format mp4 ";
    auto output = job.getJobDir() / "video.%(ext)s";
    command += "-o \"";
    command += output.string();
    command += "\" ";
    command += "\"" + job.getUrl() + "\"";
    
    std::cout << command << "\n";
    std::system(command.c_str()); 
}
