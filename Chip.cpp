#include <iostream>

typedef unsigned char BYTE;
typedef unsigned short int WORD;

class Chip {
    public:
        Chip() = default;

        void init() {
            this -> stackPtr = 0;
            this -> I = 0x0;
            this -> delayTimer = 0;
            this -> sounderTimer = 0;
        }

    private:
        // 4KB 
        char memory[4096] = {0};
        char v[16] = {0};
        char I;
        
        char chipStack[16] = {0};
        int stackPtr;

        int delayTimer;
        int sounderTimer;

        byte keys[16] = {};
        byte display[64 * 32] = {};
        /*
            BYTE m_GameMemory[0xFFF] ; // 0xFFF bytes of memory
            BYTE m_Registers[16] ; // 16 registers, 1 byte each
            WORD m_AddressI ; // the 16-bit address register I
            WORD m_ProgramCounter ; // the 16-bit program counter
            std::vector m_Stack; // the 16-bit stack
        */
};
