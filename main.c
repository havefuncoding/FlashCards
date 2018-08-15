#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Config.h"

// Forward declarations
static void run_program(FILE* file);
static int ask_to_replay();

int main(int argc, char *argv[])
{

    // Sets filepath based off argument if one is passed in
    // otherwise uses default filepath in Config.h
    char filepath[125];

    if(argc == 2) 
        strcpy(filepath, argv[1]);
    else if (argc > 2) 
        printf("\nToo many arguments!\n");
    else 
        strcpy(filepath, STUDY_FILE);

    // Checks if file is valid
    // Exits if file is not valid
    // Runs program if valid
    FILE *file;
    file = fopen(STUDY_FILE, "r");
    if (!file)
        return 1;
    else
        run_program(file);

    return 0;
}

// Runs program which prints qestion and answer lines from a file
// Inputs
// file: file object
void run_program(FILE* file)
{
    int replay;
    char buf[MAX_LEN*2];

    while (fgets(buf, MAX_LEN, file) != NULL) 
    {
        char *question = malloc(MAX_LEN * sizeof(char));
        char *answer = malloc(MAX_LEN *sizeof(char));
        char temp;
        int i;

        char *line = buf;
        char *colon;
        int index;
        colon = strchr(line, ':');
        index = (int) (colon - line);

        for (i=0; i<index; i++)
            question[i] = buf[i];
        question[++i] = '\0'; // add to end string

        for (i=index; i<strlen(buf); i++)
            answer[i-index] = buf[i];
        answer[++i] = '\0'; // add to end string

        printf("Question: %s\t[press ENTER to continue]", question);
        getchar();
        printf("Answer: %s [press ENTER to continue]", answer);
        getchar();
    }

    ask_to_replay();
}


// Asks if user wants to play again
int ask_to_replay()
{
    int replay;
    printf("Would you like to continue? [Y or N]\n");
    return 0;    
}
