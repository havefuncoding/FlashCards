#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Config.h"



int main(int argc, char *argv[])
{

    // ---- CLI Arg filepath part
    char filepath[125];

    if(argc == 2) 
        strcpy(filepath, argv[1]);
    else if (argc > 2) 
        printf("\nToo many arguments!\n");
    else 
        strcpy(filepath, STUDY_FILE);

    printf("\nFilepath to work with: %s\n", filepath);    


    // ---- Colon delimeter for Q & A part
    
    FILE *file;
    char buf[1000];

    file = fopen(STUDY_FILE, "r");
    if (!file)
        return 1;

    while (fgets(buf, 1000, file) != NULL) 
    {
        printf("Line: %s\n", buf);
        char *question = malloc(MAX_QUESTION_LEN * sizeof(char));
        char *answer = malloc(MAX_ANSWER_LEN *sizeof(char));
        char temp;
        int i;

        char *line = buf;
        char *colon;
        int index;
        colon = strchr(line, ':');
        index = (int) (colon - line);

        for (i=0; i<index; i++)
            question[i] = buf[i];
        question[++i] = '\0';

        for (i=index; i<strlen(buf); i++)
            answer[i-index] = buf[i];
        answer[++i] = '\0';

        printf("Q %s and A %s", question, answer);
        
    }


    return 0;
}
