# Chip 8 Emulator

## Chip 8 Hardware
Memory of 0x1000 bytes (4096 bytes, addresses 0x000 through 0xFFF)
16 8-Bit data registers, called V0 to VF. VF doubles as the carry flag
16 Bit address register I which is used to access memory
16 Bit program counter and a stack

## Helpful resources
http://www.codeslinger.co.uk/pages/projects/chip8/hardware.html
https://www.youtube.com/watch?v=b7ROAEMnZBE&list=PL5PyurErl12czoLyYD8za68d61T_OZsP2&index=1
https://en.wikipedia.org/wiki/CHIP-8

Run `python3 tests/memory_note.py` with a C++17 compiler to compare this byte
count with the actual `Chip` memory array and access its final byte. Only the
window is doubled; this is not a Qt build/render test or an opcode test.