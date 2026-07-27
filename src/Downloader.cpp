#include"Downloader.hpp"
#include"VideoJob.hpp"
#include<string>
#include<cstdlib>

constexpr const char* kCookies = "chrome";

constexpr const char* kFormat = "bv*[height<=720][vcodec^=avc1]+ba[acodec^=mp4a]/b";

void Downloader::download (VideoJob& job) {
    std::filesystem::create_directories(job.getJobDir());

    std::string command = "yt-dlp ";
    command += "--cookies-from-browser ";
    command += kCookies;
    command += " ";
    command += "--quiet ";
    command += "-f \"";
    command += kFormat;
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
