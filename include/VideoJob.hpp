#pragma once

#include<string>
#include<filesystem>

enum class Status {
    Pending,
    Downloading,
    Downloaded,
    Split,
    Transcribed,
    Failed
};
enum class TaskType {
    Download,
    Trancribe,
    DownloadAndTrancribe
};

class VideoJob {
private:
    std::string url;
    std::string title;
    std::string id;
    std::filesystem::path jobDir;
    Status status = Status::Pending;
    TaskType taskType = TaskType::Download;

    std::string extractVideoId(const std::string& url);
public:
    VideoJob(const std::string& newUrl);


    const std::string& getUrl();
    void setUrl (const std::string& newUrl);

    const std::string& getTitle();
    void setTitle (const std::string& newTitle);

    const std::string& getId();
    void setId(const std::string& newId);
    
    const std::filesystem::path& getJobDir();
    void setJobDir (const std::filesystem::path& newJobDir);
   
    const Status& getStatus();
    void setStatus (const Status& newStatus);

    const TaskType& getTaskType();
    void setTaskType(const TaskType& newTaskType);
};

