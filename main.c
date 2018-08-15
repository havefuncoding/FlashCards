#include <stdio.h>
#include <string.h>
#include "Config.h"


int main(int argc, char *argv[])
{
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

    return 0;
}
