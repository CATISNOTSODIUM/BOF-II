#include "runner.h"
#include "common.h"
#include "memory.h"
#include "command.h"

DebugRunner::DebugRunner(const char* file_name) {
    input_file = std::ifstream(file_name);
    if (!input_file.is_open()) {
        throw std::runtime_error("Failed to open file.");
    }
}

void DebugRunner::run() {
    std::stringstream buffer;
    buffer << input_file.rdbuf();
    std::string input = buffer.str();
    Memory mem{};
    std::cout << "[todo: debug mode]" << std::endl;
    try {
        lex_root(input).execute(mem);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
}

DebugRunner::~DebugRunner(){
    input_file.close();
}