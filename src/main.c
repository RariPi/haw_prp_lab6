#include <stdio.h>
#include <stdlib.h>

#define TASK 2

// prototypes
void task_0(int argc, char *argv[]);
void task_1(int argc, char *argv[]);
void task_2(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    int task = TASK;

    if (task == 0)
    {
        // call funktion for task 0
    }
    else if (task == 1)
    {
        // call funktion for task 1
    }
    else if (task == 2)
    {
        // call funktion for task 2
    }
    
    
    return 0;
}

void task_1(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <inputfile> <outputfile> <key>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    const int key = atoi(argv[3]);
    // char *key_as_str = argv[3];       // <- "5\0" (char*)
    // char key_as_char = key_as_str[0]; // <- '5'   (char)
    // int key = key_as_char - '0';      // <- 5     (int)

}


