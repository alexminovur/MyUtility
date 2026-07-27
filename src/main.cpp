#include<string>
#include "VideoJob.hpp"
#include"Downloader.hpp"

int main() {
    VideoJob job("https://testurl.com");

    std::cout << job.getId() << '\n' << job.getJobDir() << '\n';
    Downloader downloader;
    downloader.download(job);
    return 0;
}
