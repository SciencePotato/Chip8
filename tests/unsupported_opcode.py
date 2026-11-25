from pathlib import Path
import subprocess

root = Path(__file__).resolve().parents[1]
build = root / "build" / "unsupported-opcode"
build.mkdir(parents=True, exist_ok=True)
source = build / "UnsupportedOpcode.cpp"
source.write_text(
    "#include <cstddef>\n#include <vector>\n"
    "class MainWindow { public: std::vector<int>* displayP{};\n"
    "void setMaximumWidth(int) {} void setMaximumHeight(int) {}\n"
    "void setWindowTitle(const char*) {} void show() {} void update() {} };\n"
    '#include "../../Chip.cpp"\n'
    "int main() { Chip chip; chip.execute(); return 42; }\n"
)
program = build / "unsupported-opcode"
subprocess.run(["c++", "-std=c++17", str(source), "-o", str(program)], check=True)
result = subprocess.run([str(program)], capture_output=True, text=True, timeout=5)
assert result.returncode == 1, (result.returncode, result.stdout, result.stderr)
assert "Unsupported opcode:" in result.stdout, result.stdout
print("Actual execute rejects a cold-memory unsupported opcode with exit status 1.")
print("Only the window is doubled; no Qt rendering or unfinished opcode is tested.")
