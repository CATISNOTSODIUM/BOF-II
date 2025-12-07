#ifndef BOF_RUNNER
#define BOF_RUNNER

#include "common.h"

class Runner {
public:
    virtual void run() {}
};


class InteractiveRunner : Runner {
public:
    void run();
};


class FileRunner : Runner {
public:
    FileRunner(const char* file_name);
    ~FileRunner();
    FileRunner(const FileRunner&) = delete;
    FileRunner& operator=(const FileRunner&) = delete;
    FileRunner(FileRunner&&) = delete;
    FileRunner& operator=(FileRunner&&) = delete;

    void run();
private:
    std::ifstream input_file;
};

#endif