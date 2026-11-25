# Chip 8 Emulator

Unsupported opcode diagnostics terminate with a failure status, not success.
Run `python3 tests/unsupported_opcode.py` with a C++17 compiler to check the
actual cold-memory rejection path. Only the window is doubled; this is not a
Qt rendering test and does not complete the loader or instruction handlers.

## Chip 8 Hardware
Memory of 0xFFF bytes
16 8-Bit data registers, called V0 to VF. VF doubles as the carry flag
16 Bit address register I which is used to access memory
16 Bit program counter and a stack

## Helpful resources
http://www.codeslinger.co.uk/pages/projects/chip8/hardware.html
https://www.youtube.com/watch?v=b7ROAEMnZBE&list=PL5PyurErl12czoLyYD8za68d61T_OZsP2&index=1
https://en.wikipedia.org/wiki/CHIP-8