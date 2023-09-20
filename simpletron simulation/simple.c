#include <stdio.h>
#include "simple.h"

int main(int argc, char *argv[])
{
    //if file not given at time execution then generating error
    if (argc != 2)
    {
        printf("\n\n>>>>>>>>>    Please provide .sml file. Format: %s <program.sml>\n\n", argv[0]);
        return 1;
    }
    printf("\n********      Welcome to simpletron simulation      *********\n");
    
    load_program(argv[1]);
    printf("\n********* Program loaded into memory *********");

    printf("\n\n**********         The Memory after loading is          ***********\n\n\n");

    display_memory(); //displaying memory
    
    //Executing instruction from memory
    executeProgram();
    printf("\n\n**********         The Memory after execution is          ***********\n\n\n");

    display_memory(); //displaying memory

    printf("\n\n***************          Simpletron execution terminated          ************\n\n");
    return 0;
}
