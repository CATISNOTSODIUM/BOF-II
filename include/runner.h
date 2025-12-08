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

class DebugRunner : Runner {
public:
    DebugRunner(const char* file_name);
    ~DebugRunner();
    DebugRunner(const DebugRunner&) = delete;
    DebugRunner& operator=(const DebugRunner&) = delete;
    DebugRunner(DebugRunner&&) = delete;
    DebugRunner& operator=(DebugRunner&&) = delete;

    void run();
private:
    std::ifstream input_file;
};

#endif