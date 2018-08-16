#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Config.h"

// Forward declarations
static void run_program(FILE* file);
static int ask_to_replay(FILE* file);
char* get_filepath(int argc, char *argv[]);

int main(int argc, char *argv[])
{

    // Gets and sets filepath
    // If argument is passed in, then uses input filepath
    // If no argument is passed in, then uses default filepath in Config.h
    char filepath[125];
    if(argc == 2) 
        strcpy(filepath, argv[1]);
    else if (argc > 2) 
        printf("\nToo many arguments!\n");
    else 
        strcpy(filepath, STUDY_FILE);

    // Gets file object
    int lines_allocated = 128;
    int max_line_len = 100;
    char **words = (char **)malloc(sizeof(char *)*lines_allocated);
    
    FILE *fp = fopen(filepath, "r");
    int i;
    for (i = 0; 1; i++) // Check 1 in the middle
    {
        int j;
    
        // Check if line allocation exceeded
        if (i >= lines_allocated)
        {
            int new_size;
            
            // Double our allocation and re-allocate
            new_size = lines_allocated * 2;
            words = (char **)realloc(words, sizeof(char*)*new_size);
            lines_allocated = new_size;
        }
        
        // Allocate space for next line
        words[i] = malloc(max_line_len);
        if (fgets(words[i], max_line_len-1, fp) == NULL)
            break;

        // Get rid of CR or LF at end of line
        for (j = strlen(words[i])-1;
             j>=0 && (words[i][j]=='\n' || words[i][j]=='\r');
             j--)
        ;
        words[i][j+1] = '\0';
    }

    // Close file
    fclose(fp);

    // ---------------------------------------------------------------
    
    int replay = 0; // 1 for yes, 0 for no
    do
    {
        int j;
        for (j = 0; j < i; j++) {
            printf("Words[j] %i: %s\n", j, words[j]);
            
            // questions and answers
            char *question = malloc(MAX_LEN * sizeof(char));
            char *answer = malloc(MAX_LEN *sizeof(char));
            char temp;
            int y;

            char *line = words[j];
            char *colon;
            int index;
            colon = strchr(line, ':');
            index = (int) (colon - line);

            for (y=0; y<index; y++)
                question[y] = words[j][y];
            question[++y] = '\0'; // add to end string

/*            for (y=index; y<strlen(words[j]); y++)
                answer[y-index] = words[j][y];
            answer[++y] = '\0'; // add to end string
*/
        }

    } while (replay == 1);  


    // --------------------------------------------------------------

    // Good practice to free memory
    for (; i >= 0; i--) // TODO: ; initialized
        free(words[i]);
    free(words);

        
    return 0;
}

