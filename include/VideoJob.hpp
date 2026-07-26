#include<string>

#ifndef VIDEO_HPP
#define VIDEO_HPP
#endif


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
    std::string dir;
    std::string pathToVideo;
    std::string pathToText;
    Status status = Status::Pending;
    TaskType tasktype = TaskType::Download;

public:
    VideoJob(const std::string& newUrl);


    const std::string& getUrl();
    void setUrl (const std::string& newUrl);

    const std::string& getDir();
    void setDir(const std::string& newDir);
    
    const std::string& getPathToVideo();
    void setPathToVideo(const std::string& newPathToVideo);
    
    const std::string& getPathToText();
    void setPathToText(const std::string& newPathToText);

    const Status& getStatus();
};

