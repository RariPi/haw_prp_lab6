#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define TASK 3

// prototypes
#if TASK == 3
int *find_int(int *arr, int arr_len, int num);
#endif

#if TASK == 1
int main(int argc, char *argv[])
{
    for(int i = 0; i < argc; i++)
    {
        printf("Parameter[%d]: \"%s\"", i, argv[i]);
    }
}
#elif TASK == 2
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <inputfile> <outputfile> <key>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    //CLI in pointer bzw int speichern
    const char *input_file = argv[1];
    const char *output_file = argv[2];
    //atoi wandelt ascii wert der Zahl in integer wert der Zahl um
    const int key = atoi(argv[3]);
    // char *key_as_str = argv[3];       // <- "5\0" (char*)
    // char key_as_char = key_as_str[0]; // <- '5'   (char)
    // int key = key_as_char - '0';      // <- 5     (int)

    // öffne die datei im read modus
    FILE *input = fopen(input_file, "r");
   //checken auf fehler beim öffnen
    if (input == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    //datein inhalt in array speichern 
    char message[1024];
    fgets(message, 1024, input);

    // Cäsar verschlüsselung
    int length = strlen(message);

    //Schleife um jeden charakter einzeln zu verschlüsseln
    for (int i = 0; i < length; i++)
    {
        message[i] = toupper(message[i]);
        if (isalpha(message[i]))
        {
            message[i] = (message[i] - 'A' + key) % 26 + 'A';
        }
    }
   

    //neue datei im write modus öffnen und die verschlüsselte nachricht darin speichern
    FILE *output = fopen(output_file, "w");
    if (output == NULL)
    {
        printf("Datei konnte nicht geöffnet werden\n");
        exit(EXIT_FAILURE);
    }
    fputs(message, output);
    fclose(input);
    fclose(output);
    
}
#elif TASK == 3
int main(int argc,char *argv[])
{
    // Declare array of numbers
    size_t numbers_len = 7;
    int numbers[7] = { 1, 2, 3, 4, 5, 1, 6 };
   
    printf("Verfügbare Werte:[");
    for (int i = 0; i < numbers_len; i++)
    {
        printf("%2d,", numbers[i]);
    }
    printf("]\n");

    // Set value to be searched for
    int num = 0;
    printf("Gesuchter Wert: ");
    scanf("%d", &num);

    bool end_of_array = false;

    // Pointer to an address in the array
    int *current_ptr;

    // Set current_ptr to first index/address
    current_ptr = &(numbers[0]);

    // Remaining size of array
    size_t arr_len_from_ptr = numbers_len;

    // Loop over array until end of array is reached

    do
    {
        // Find first index/address of number "num"
        current_ptr = find_int(current_ptr, arr_len_from_ptr, num);
        
        // Check for NULL ptr
        // If NULL, no more integers were found
        if (current_ptr == NULL)
        {
            // Break while loop
            end_of_array = true;
        }
        else
        {
            // Found another element
            size_t pos_of_element = current_ptr - numbers;
            printf("Gefunden:%2d an der Pos. %zu mit der Adresse: %p\n", *current_ptr, pos_of_element+1, current_ptr);

            // Increment current_ptr to the next address
            // 0 5 7 4 8 1 7 2 9 4 (size: 10)
            //   |
            current_ptr++;
            // 0 5 7 4 8 1 7 2 9 4 [X X X X ...] (remaining size: 8)
            //     |                Garbage values (outside)
            // Start new iteration from 7, not 5
            // Otherwise, infinite loop

            // Calculate remaining array size
            // Remaining array size is NOT 10 anymore, but 8!!!
            size_t diff_start_current_ptr;

            // Subtracting two pointers return element count (!) 
            // and NOT byte difference
            diff_start_current_ptr = current_ptr - numbers;

            arr_len_from_ptr = numbers_len - diff_start_current_ptr;
        }
    
    } while(!end_of_array);

    return 0;
}

int *find_int(int *arr, int arr_len, int num)
{
    for(int i = 0; i < arr_len; i++)
    {
        if (arr[i] == num)
        {
            return &arr[i];
            
        }
    }

    return NULL;
}
#endif