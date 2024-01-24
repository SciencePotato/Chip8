#include <iostream>
#include <vector>
#include <unistd.h>

typedef unsigned char BYTE;
typedef unsigned short int WORD;

class Chip {
    public:
        Chip() = default;

        void init() {
            this -> stackPtr = 0;
            this -> I = 0x0;
            this -> pc = (char) 0x200;
            this -> delayTimer = 0;
            this -> sounderTimer = 0;

            // Window showing
            window.setMaximumWidth(640);
            window.setMaximumHeight(320);
            window.setWindowTitle("Chip 8 Emulator");
            window.show();
            window.displayP = &display;
            display[0] = 1;
            display[50] = 1;

            window.update();
        }

        void execute() {
            // Fetch opcode 
            char opcode = memory[pc] << 8 | memory[pc + 1];
            // Decode 
            switch (opcode & 0xF000) {
                case 0x8000: // Contains more data in last bit

                    switch (opcode & 0x000F) {
                        case 0x0000:    //8XY0: Set VX to the value of VY
                            break;
                        default:        
                            std::cout << "Unsupported opcode: " << opcode;
                            exit(0);
                            break;
                    }

                    break;
                default:
                    std::cout << "Unsupported opcode: " << opcode;
                    exit(0);
            }
        }

    private:
        MainWindow window;
        // 4KB
        char memory[4096] = {0};
        char v[16] = {0};
        char I;
        char pc;
        
        char chipStack[16] = {0};
        int stackPtr;

        int delayTimer;
        int sounderTimer;

        std::byte keys[16] = {};
        std::vector<int> display = std::vector<int>(64 * 32, 0);;
        // Scale this up | otherwise you can't see shit
        /*
            BYTE m_GameMemory[0xFFF] ; // 0xFFF bytes of memory
            BYTE m_Registers[16] ; // 16 registers, 1 byte each
            WORD m_AddressI ; // the 16-bit address register I
            WORD m_ProgramCounter ; // the 16-bit program counter
            std::vector m_Stack; // the 16-bit stack
        */
};
