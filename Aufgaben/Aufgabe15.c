#include <stdio.h>
#include <String.h>
/* ============================================================================
 * Name : sortCLParameters.c
 * Author : Alexander Lux
 * Version : 1.0
 * Description : Wandelt command line input in kleinbuchstaben und danach alphabetisch sortiert. No input => Error Code
 * ============================================================================ */

int main(int argc, const char * argv[])
{
    char temp[80];
    if(argc < 2) {
        printf("This programm need Commandline inputs\n");
        return -1;
    }

    for(int i = 1; i < argc; i++) {
        printf("%s\n", strlwr(argv[i]));
    }
    printf("\nSort....\n\n");
    for(int i = 1; i < argc; i++) {
        for(int j = 1; j < argc; j++) {
            if(argv[i][0] < argv[j][0]) {
                //printf("%d-%d\n", argv[i][0], argv[j][0]);
                strcpy(temp, argv[i]);
                strcpy(argv[i], argv[j]);
                strcpy(argv[j], temp);
            }
        }
    }

    for(int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    return 0;
}
