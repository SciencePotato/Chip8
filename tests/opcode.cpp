#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>

// Replace only the Qt window; exercise the actual CPU implementation.
class MainWindow {
public:
    std::vector<int>* displayP{};
    void setMaximumWidth(int) {}
    void setMaximumHeight(int) {}
    void setWindowTitle(const char*) {}
    void show() {}
    void update() {}
};

#define private public
#include "../Chip.cpp"
#undef private

bool decoded = false;

int main(int argc, char**) {
    std::atexit([] { assert(decoded); });
    Chip chip;
    chip.init();
    if (argc == 1) {
        assert(chip.pc == 0x200);
    } else {
        chip.pc = 0;
    }
    chip.memory[chip.pc] = 0x81;
    chip.memory[chip.pc + 1] = 0xE0;
    chip.execute();
    decoded = true;
    std::cout << "Decoded 0x81E0 at 0x" << std::hex << chip.pc << "\n";
}
