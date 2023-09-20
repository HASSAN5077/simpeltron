#include <stdio.h>
#include "simple.h"

#define MEMORY_SIZE 100
static int memory[MEMORY_SIZE];

// Loading a values from file
void load_program(char *filename) {
    FILE *file = fopen(filename, "r");
    int i = 0;
    while (fscanf(file, "%d", &memory[i]) != EOF) {
        i++;
    }
    fclose(file);
}

// printing memory
void display_memory() {

    printf("    ");
    for(int i=0; i<10; i++){
        printf("%5d   ", i); //Printing index from 0 to 9//
    }
    for(int count=0; count<MEMORY_SIZE; count++){
        if(count%10==0){
            printf("\n%3d   ", count); //Printing a new line and current multiple of ten in the start of every row//
        }
        printf("+%04d   ", memory[count]); //Printing 10 values from the memory in the form of a row//
    }
}

//executing instruction in memory

void executeProgram(){
    int accumulator = 0;
    int instruction_counter = 0;


    while (instruction_counter < MEMORY_SIZE)
    {
        int instruction = memory[instruction_counter++];
        int operand = instruction % 100;
        int opcode = instruction / 100;

        printf("\n\n>>>>>>>>>         The instruction number is: %d\n", instruction_counter - 1);
        printf("\nThe opcode is: %d", opcode);
        printf("\nThe operand is: %d", operand);
        printf("\nThe accumulator value is: %d ", accumulator);
        switch (opcode)
        {
        case READ:
            printf("\n\nEnter an integer: ");
            scanf("%d", &memory[operand]);
            break;
        case WRITE:
            printf("\nThe value after calculation is: %d\n", memory[operand]);
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
            if (memory[operand] != 0)
            {
                accumulator /= memory[operand];
            }
            else
            {
                printf("\nError: Division by zero\n");
            }
            break;
        case MULTIPLY:
            accumulator *= memory[operand];
            break;
        case BRANCH:
            instruction_counter = operand;
            break;
        case BRANCHNEG:
            if (accumulator < 0)
            {
                instruction_counter = operand;
            }
            break;
        case BRANCHZERO:
            if (accumulator == 0)
            {
                instruction_counter = operand;
            }
            break;
        case HALT:
            printf("\n\nExecution done. Program halted...");
            break;
        default:
            printf("\n\n\nError: Invalid opcode\n");
            break;
        }
        if (instruction / 100 == HALT)
        {
            break;
        }
    }
    
 }