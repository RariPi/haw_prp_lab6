#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// prototypes
void task_0(int argc, char *argv[]);
void task_1(int argc, char *argv[]);
int task_2(int argc, char *argv[]);
int *find_int(int adress, int *array, int len);

#define TASK 3

int main(int argc, char *argv[])
{
    int task = TASK;
    if (task == 1)
    {
        task_0(argc, argv);
    }
    else if (task == 2)
    {
        task_1(argc, argv);
    }
    else if (task == 3)
    {
        task_2(argc, argv);
    }
}

void task_0(int argc, char *argv[])
{
    for(int i = 0; i < argc; i++)
    {
        printf("Parameter[%d]: \"%s\"", i, argv[i]);
    }
}

void task_1(int argc, char *argv[])
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


int task_2(int argc,char *argv[])
{
    int array[7] = { 1, 2, 3, 4, 5, 1, 6 };
    int len = sizeof(array) / sizeof(int);
   
    printf("Verfügbare Werte:[");
    for (int i = 0; i < len; i++)
    {
        printf(" %d,", array[i]);
    }
    printf("]\n");
    int number;
    printf("Gesuchter Wert: ");
    scanf("%d", &number);

    int end_of_array = 0;
    int *rckgabe = array;

    do
    {
        rckgabe = find_int(number, rckgabe, len);
        
        if (rckgabe != NULL)
        {
            printf("Gefunden:%d mit der adresse:%p", *rckgabe, &rckgabe);
            printf("\n");

            rckgabe = array;
        }
        else
        {
            end_of_array = 1;
        }
    
    }while(!end_of_array);

    return 0;
}

int *find_int(int number, int *array, int len)
{
    for(int i = 0; i < len; i++)
    {
        if (array[i] == number)
        {
            return &array[i];
            
        }
    }
    return NULL;
}
