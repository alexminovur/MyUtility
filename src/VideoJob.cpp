#include<iostream>
#include<string>

#include "VideoJob.hpp"


VideoJob::VideoJob(const std::string& newUrl): dir("TestDir/NewVideo") {
    std::cout << "Im ready!" << '\n';
    std::cout << "Input URL: "; std::cin >> url;
    std::cout << "URL = " << url;
}

void VideoJob::setUrl(const std::string& newUrl) { url = newUrl; }
const std::string& VideoJob::getUrl() { return url; }

void VideoJob::setDir(const std::string& newDir) { dir = newDir; }
const std::string& VideoJob::getDir() { return dir; }

void VideoJob::setPathToVideo(const std::string& newPathToVideo) { pathToVideo = newPathToVideo; }
const std::string& VideoJob::getPathToVideo() { return pathToVideo; }

void VideoJob::setPathToText(const std::string& newPathToText) { pathToText = newPathToText; }
const std::string& VideoJob::getPathToText() { return pathToText; }

const Status& VideoJob::getStatus () { return status; }
