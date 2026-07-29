#include<string>
#include "VideoJob.hpp"
#include"Downloader.hpp"
#include"AudioExtractor.hpp"
#include"Transcriber.hpp"

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
    int y = 0;
    std::cout << "Transcribe need?" << '\n' << "[1/0]";
    std::cin >> y;
    if (y) {
        Transcriber transcribe;
        transcribe.split(job);
        transcribe.transcribeChunks(job);
        transcribe.merge(job);
    }
    return 0;
}
