#include "runner.h"
#include "common.h"
#include "memory.h"
#include "command.h"

FileRunner::FileRunner(const char* file_name) {
    input_file = std::ifstream(file_name);
    if (!input_file.is_open()) {
        throw std::runtime_error("Failed to open file.");
    }
}

void FileRunner::run() {
    std::stringstream buffer;
    buffer << input_file.rdbuf();
    std::string input = buffer.str();
    Memory mem{};
    try {
        lex_root(input).execute(mem);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
}

FileRunner::~FileRunner(){
    input_file.close();
}