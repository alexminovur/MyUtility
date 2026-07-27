#include<iostream>
#include<string>

#include "VideoJob.hpp"


VideoJob::VideoJob(const std::string& newUrl) {
    std::cout << "Im ready!" << '\n';
    std::cout << "Input URL: "; std::cin >> url;
    std::cout << "URL = " << url;
    
    id = extractVideoId(url);
    jobDir = std::filesystem::path("workspace") / "jobs" / id;
}

std::string VideoJob::extractVideoId(const std::string& url) {
    if (url.find("youtu.be/") != std::string::npos) {
        std::string id = url.substr(url.find("youtu.be/") + 9);
        if (id.find("?") != std::string::npos) {
            id.erase(id.find("?"));
        }
        return id;
    }
    else if (url.find("watch?v=") != std::string::npos) {
        std::string id = url.substr(url.find("v=") + 2);
        if (id.find("&") != std::string::npos) {
            id.erase(id.find("&"));
        }
        return id;
    }
    return "";
}

void VideoJob::setUrl(const std::string& newUrl) { url = newUrl; }
const std::string& VideoJob::getUrl() { return url; }

void VideoJob::setTitle(const std::string& newTitle) { title = newTitle; }
const std::string& VideoJob::getTitle() { return title; }

void VideoJob::setId(const std::string& newId) { id = newId; }
const std::string& VideoJob::getId() { return id; }

void VideoJob::setJobDir(const std::filesystem::path& newJobDir) { jobDir = newJobDir; }
const std::filesystem::path& VideoJob::getJobDir() { return jobDir; }

void VideoJob::setStatus(const Status& newStatus) { status = newStatus; }
const Status& VideoJob::getStatus () { return status; }

void VideoJob::setTaskType(const TaskType& newTaskType) { taskType = newTaskType; }
const TaskType& VideoJob::getTaskType () { return taskType; }

