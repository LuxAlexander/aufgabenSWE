#include <stdio.h>
#include <stdlib.h>

/* ============================================================================
 * Name : displaySourceComments.c
 * Author : Alexander Lux
 * Version : 1.0
 * Description : Lese Kommentare von C-Files, gib sie aus. Fehler Meldung bei keinen. Option diese in Datei zu schreiben.
 * ============================================================================ */

int main(void) {

    FILE *fptr=NULL;
    FILE *write=NULL;

    char character=' ';
    int comend=0;
    int option=0;

    fptr=fopen("..\\test.c","r");

    if(fptr==NULL) {
        fprintf(stderr,"Error in opening file\n");
        exit(-1);
    }

    printf("Wanna write in file:0/No,1/Yes");
    scanf("%d",&option);


    if(option==1) {
        write=fopen("..\\write.txt","w");
        if(write==NULL) {
            exit(-1);
        }
    }

    while((character=fgetc(fptr))!=EOF) {
        if(character=='/') {
            if((character=fgetc(fptr))=='/') {
                printf("//");
                if (option==1)fprintf(write,"//");
                    while((character=fgetc(fptr))!='\n'&& character!=EOF) {
                        printf("%c", character);
                        if (option==1)fputc(character,write);
                    }
                    printf("\n");

                    if (option==1)fprintf(write,"\n");

            }else if(character=='*') {
                printf("/*");
                if (option==1)fprintf(write,"/*");
                while((character=fgetc(fptr))!=EOF && comend!=1) {
                    if (character=='*') {
                        if ((character=fgetc(fptr))=='/') {
                            comend=1;
                            printf("*/\n");
                            fprintf(write,"*/\n");
                        }
                    }else {
                        printf("%c", character);
                        if (option==1)fputc(character,write);
                    }
                }
                comend=0;
                printf("\n");
            }

        }
    }

    //Let's assume I would really put in the work for it.
    //I would malloc a suitible size to save normal comments into it and add space if needed

    if(write)fclose(write);
    fclose(fptr);

    return 0;
}