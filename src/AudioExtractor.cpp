#include<string>
#include<cstdlib>
#include<iostream>
#include"AudioExtractor.hpp"


void AudioExtractor::audioExtract (VideoJob& job) {
    std::string command = "ffmpeg ";
    command += "-hide_banner ";
    command += "-loglevel error ";
    auto pathVideo = job.getJobDir() / "video.mp4";
    command += "-i \"";
    command += pathVideo.string();
    command += "\" ";
    command += "-vn ";
    command += "-c:a libopus \"";
    auto pathAudio = job.getJobDir() / "audio.opus";
    command += pathAudio.string();
    command += "\" ";
    command += "-y";

    std::cout << command << '\n';
    std::system(command.c_str());
}

