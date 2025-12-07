#include "runner.h"
#include "common.h"

FileRunner::FileRunner(const char* file_name) {
    input_file = std::ifstream(file_name);
    if (!input_file.is_open()) {
        throw std::runtime_error("Failed to open file.");
    }
}

void FileRunner::run() {
    std::cout << "Reading file ..." << std::endl;
    char ch;
    while (input_file.get(ch)) {
        std::cout << ch;
    }
    std::cout << "\nEnd file" << std::endl;
}

FileRunner::~FileRunner(){
    input_file.close();
}