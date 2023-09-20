#include <stdio.h>

#define MEMORY_SIZE 100 // The Simpletron has 100 memory locations
#define READ 10 // The opcode for read instruction
#define WRITE 11 // The opcode for write instruction
#define LOAD 20 // The opcode for load instruction
#define STORE 21 // The opcode for store instruction
#define ADD 30 // The opcode for add instruction
#define SUBTRACT 31 // The opcode for subtract instruction
#define DIVIDE 32 // The opcode for divide instruction
#define MULTIPLY 33 // The opcode for multiply instruction
#define BRANCH 40 // The opcode for branch instruction
#define BRANCHNEG 41 // The opcode for branch negative instruction
#define BRANCHZERO 42 // The opcode for branch zero instruction
#define HALT 43 // The opcode for halt instruction

int memory[MEMORY_SIZE]; // The Simpletron's memory
int accumulator = 0; // The Simpletron's accumulator
int instructionCounter = 0; // The Simpletron's instruction counter
int instructionRegister = 0; // The Simpletron's instruction register
int operationCode = 0; // The Simpletron's operation code
int operand = 0; // The Simpletron's operand

int main() {
    printf("*** Welcome to Simpletron! ***\n");
    printf("*** Please enter your program one instruction ***\n");
    printf("*** (or data word) at a time. I will type the ***\n");
    printf("*** location number and a question mark (?).  ***\n");
    printf("*** You then type the word for that location. ***\n");
    printf("*** Type the sentinel -99999 to stop entering ***\n");
    printf("*** your program. ***\n\n");

    int location = 0;
    int word = 0;
    do {
        printf("%02d ? ", location);
        scanf("%d", &word);
        memory[location] = word;
        location++;
    } while (word != -99999 && location < MEMORY_SIZE);

    printf("*** Program loading completed ***\n");
    printf("*** Program execution begins  ***\n\n");

    while (instructionCounter < MEMORY_SIZE) {
        // Fetch the instruction
        instructionRegister = memory[instructionCounter];
        operationCode = instructionRegister / 100;
        operand = instructionRegister % 100;

        // Execute the instruction
        switch (operationCode) {
            case READ:
                printf("Enter an integer: ");
                scanf("%d", &memory[operand]);
                break;
            case WRITE:
                printf("%d\n", memory[operand]);
                break;
            case LOAD:
                accumulator = memory[operand];
                break;
            case STORE:
                memory[operand] = accumulator;
                break;
            case ADD:
                accumulator += memory[operand];
                break;
            case SUBTRACT:
                accumulator -= memory[operand];
                break;
            case DIVIDE:
                if (memory[operand] == 0) {
                    printf("*** Attempt to divide by zero ***\n");
                    printf("*** Simpletron execution abnormally terminated ***\n");
                    return 1;
                }
                accumulator /= memory[operand];
                break;
            case MULTIPLY:
                accumulator *= memory[operand];
                break;
            case BRANCH:
                instructionCounter = operand;
                break;
            case BRANCHNEG:
                if (accumulator < 0) {
                    instructionCounter = operand;
                }
                break;
            case BRANCHZERO:
                if (accumulator == 0) {
                    instructionCounter = operand;
                }
                break;
            case HALT:
                printf("*** Simpletron execution terminated ***\n");
                default:
                printf("*** Invalid operation code ***\n");
                printf("*** Simpletron execution abnormally terminated ***\n");
        }
        instructionCounter++;
    }
}