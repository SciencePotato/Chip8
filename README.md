# Chip 8 Emulator

## Chip 8 Hardware
Memory of 0xFFF bytes
16 8-Bit data registers, called V0 to VF. VF doubles as the carry flag
16 Bit address register I which is used to access memory
16 Bit program counter and a stack

## Helpful resources
http://www.codeslinger.co.uk/pages/projects/chip8/hardware.html
https://www.youtube.com/watch?v=b7ROAEMnZBE&list=PL5PyurErl12czoLyYD8za68d61T_OZsP2&index=1
https://en.wikipedia.org/wiki/CHIP-8

## Focused CPU regression

The program counter and fetched opcode must retain all 16 bits. Memory bytes
are unsigned so a low byte with its high bit set does not sign-extend.

```sh
mkdir -p build
c++ -std=c++17 tests/opcode.cpp -o build/opcode-test
./build/opcode-test
```

This compiles the actual `Chip.cpp` with a no-op window double; it checks
initialization at `0x200` and decoding `0x81E0`. It does not test Qt rendering
or implement the unfinished ROM loader or instruction handlers.