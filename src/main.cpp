#include<string>
#include "VideoJob.hpp"
#include"Downloader.hpp"
#include"AudioExtractor.hpp"

int main() { 
    VideoJob job("NoneURL");
    std::cout << job.getId() << '\n' << job.getJobDir() << '\n';
    Downloader downloader;
    downloader.download(job);

    int x = 0;
    std::cout << "Audio need?" << '\n' << "[1/0]";
    std::cin >> x;
    if (x) {
        AudioExtractor audioExtractor;
        audioExtractor.audioExtract(job);
    }
    
    return 0;
}
