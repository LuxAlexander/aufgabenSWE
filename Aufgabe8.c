#include <stdio.h>
#define len 21
/*Erstellen Sie ein C-Programm mystrcmp, das zwei Zeichenketten einliest, überprüft,
 *ob die beiden Strings gleich sind und das Ergebnis ausgibt.
 *Verwenden Sie zum Einlesen der Strings die Funktion getchar(). Es sollen keine string.h Funktionen verwendet werden*/

int main(void) {
    char stringone[len]={},stringtocomp[len]={};
    int compare=1, i=0;
    printf("Programm to compare two strings!\n");

    //There should be a function for the input
    printf("Please enter the first string:\n");
    for(;i<=len && (stringone[i]=getchar())!='\n';i++);
    stringone[i]='\0';

    printf("Please enter the second string:\n");
    for(i=0;i<=len && (stringtocomp[i]=getchar())!='\n';i++);
    stringtocomp[i]='\0';

    //Function for comparing would be nice
    printf("Strings are getting compared...\n");
    for(int i=0;(stringtocomp[i]!='\0' || stringone[i]!='\0' )&&compare==1;i++) {
        if(stringone[i]!=stringtocomp[i]) {
            compare=0;
        }
    }

    printf("%s and %s ",stringone,stringtocomp);

    if(compare==1) {
        printf("are the same!\n");
    }else printf("are not the same!\n");

    return 0;
}
