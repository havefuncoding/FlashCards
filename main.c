#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Config.h"



int main(int argc, char *argv[])
{

    // ---- CLI Arg filepath part
    char filepath[125];

    if(argc == 2) {
        printf("\nArgument: %s\n", argv[1]);
        strcpy(filepath, argv[1]);
    } else if (argc > 2) {
        printf("\nToo many arguments!\n");
    } else {
        printf("\nNo argument supplied.\n");
        strcpy(filepath, STUDY_FILE);
    }

    printf("\nFilepath to work with: %s\n", filepath);    


    // ---- Colon delimeter for Q & A part
    FILE *file;
    char *question = malloc(MAX_QUESTION_LEN * sizeof(char));
    char *answer = malloc(MAX_ANSWER_LEN *sizeof(char));
    char temp;
    int i = 0;

    file = fopen(filepath, "r");

    while ((temp = fgetc(file)) != EOF)
    {
        if (temp == ':')
            break;
        question[i++] = temp;
    }
    question[++i] = '\0';

    i = 0;
    while ((temp = fgetc(file)) != EOF)
    {
        if (temp == '\n')
            break;
        answer[i++] = temp;
    }
    answer[++i] = '\0';

    fclose(file);

    printf ("Question: %s\n", question);
    printf ("Answer: %s\n", answer);


    return 0;
}
