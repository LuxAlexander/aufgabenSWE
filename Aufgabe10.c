#include <stdio.h>
#include <string.h>
#define len 20
/*Erstellen Sie ein C-Programm mystrcat,
 *das zwei Zeichenketten einliest und den zweiten String an den ersten hinzufügt.
 *Das Ergebnis soll dann ausgegeben werden. Es sollen keine string.h Funktionen verwendet werden*/

int main(void) {
    char str[len],str2[len],str3[len*2];
    int i=0,j=0;//i is for the index for the two strings and j to track the current element for the combination

    printf("Ersten String eingeben!\n");
    scanf("%s",str);

    printf("Zwei String eingeben:\n");
    scanf("%s",str2);

    //a function would make this look pretty, since it's redundant
    while(str[i]!='\0') {
        str3[i]=str[i];
        i++;
    }

    j=i;
    i=0;

    while(str2[i]!='\0') {
        str3[j+i]=str2[i];
        i++;
    }

    str3[j]='\0';//the last place of the combination should be the terminator

    printf("Kombination: %s",str3);
    return 0;
}
