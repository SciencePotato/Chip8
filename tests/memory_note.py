from pathlib import Path
import re
import subprocess

root = Path(__file__).resolve().parents[1]
size = re.search(r"Memory of (0x[0-9A-Fa-f]+) bytes",
                 (root / "README.md").read_text()).group(1)
build = root / "build" / "memory-note"
build.mkdir(parents=True, exist_ok=True)
source = build / "memory.cpp"
source.write_text(
    "#include <cassert>\n#include <cstddef>\n#include <iostream>\n#include <vector>\n"
    "class MainWindow { public: std::vector<int>* displayP{};\n"
    "void setMaximumWidth(int) {} void setMaximumHeight(int) {}\n"
    "void setWindowTitle(const char*) {} void show() {} void update() {} };\n"
    "#define private public\n"
    '#include "../../Chip.cpp"\n#undef private\n'
    "int main() { Chip chip;\n"
    "static_assert(sizeof(chip.memory) == " + size + ");\n"
    "chip.memory[sizeof(chip.memory) - 1] = 42;\n"
    "assert(chip.memory[4095] == 42);\n}\n"
)
subprocess.run(["c++", "-std=c++17", str(source), "-o", str(build / "memory")], check=True)
subprocess.run([str(build / "memory")], check=True)
print("Documented byte count equals actual CPU storage, including address 0xFFF.")
