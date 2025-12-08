#include "runner.h"
#include "common.h"
#include "memory.h"
#include "command.h"
#include <format>
#include <ncurses.h>

DebugRunner::DebugRunner(const char* file_name) {
    input_file = std::ifstream(file_name);
    input_file_name = file_name;
    if (!input_file.is_open()) {
        throw std::runtime_error("Failed to open file.");
    }
}

void rectangle(int y1, int x1, int y2, int x2)
{
    mvhline(y1, x1, 0, x2-x1);
    mvhline(y2, x1, 0, x2-x1);
    mvvline(y1, x1, 0, y2-y1);
    mvvline(y1, x2, 0, y2-y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}

class MemoryDisplayer {
public:
    MemoryDisplayer(Memory& mem): mem(mem) {}
    
    void render() {
        int x_offset = 0;
        int y_offset = 0;
        int y_width = 2;
        int gap = 1;
        int padding = 2;
        int x_width = y_width * 2 + 2 * padding;
        int max_num = getmaxx(stdscr) / x_width;


        // print memory layout 
        int pc = mem.get_pc();
        int left_bound = std::max(0, pc - 4);

        for (int i = 0; i < max_num; i++) {
            int left = x_offset + x_width * i + padding;
            int right = left + x_width - padding;
            rectangle(y_offset, left, y_offset + y_width, right);
            std::ostringstream oss;
            oss << mem.get_value(left_bound + i);
            std::string msg = oss.str();
            if (left_bound + i == mem.get_pc()) {
                mvprintw(2 * y_offset + y_width, (left + right - 2) / 2, " ^ ");
            }
            mvprintw(y_offset + y_width / 2, (left + right - msg.length() / 2) / 2, msg.c_str());
        }
    }
private:
    Memory& mem;
    int num_box;
};


void DebugRunner::run() {
    std::stringstream buffer;
    buffer << input_file.rdbuf();
    std::string input = buffer.str();
    Memory mem{};
    MemoryDisplayer mem_display{mem};
    std::cout << "[todo: debug mode]" << std::endl;
    try {
        lex_root(input).execute(mem);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    int y_max, x_max;
    initscr();
    noecho();
    curs_set(0);
    getmaxyx(stdscr, y_max, x_max);

    mem_display.render();
    refresh();
	getch();
	endwin();
}

DebugRunner::~DebugRunner(){
    input_file.close();
}