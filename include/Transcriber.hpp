 #pragma once
#include<cstdlib>
#include"VideoJob.hpp"

class Transcriber {
public:
    int chunkTime = 600;

    void split(VideoJob& job);
    void transcribeChunks(VideoJob& job);
    void merge(VideoJob& job);
    void cleanup(VideoJob& job);

    void transcribe(VideoJob& job);
};
