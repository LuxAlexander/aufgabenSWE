#include <stdio.h>
#include <String.h>
#define SIZE 10
/* ============================================================================
 * Name : customerList.c
 * Author : Alexander Lux
 * Version : 1.0
 * Description : KundinnenListe MIT Kunde (ID, Name, Adresse, EMail); bei '-' stop, alphb absteigend ausgabe, sorttiert egal
 * ============================================================================ */

typedef struct Kundinnen {
    int ID;
    char Name[20];
    char Adresse[20];
    char EMail[20];
}customer;

void swap(customer *a, customer *b) {
    strcpy((*b).Name, (*a).Name);
    strcpy((*b).Adresse, (*a).Adresse);
    strcpy((*b).EMail, (*a).EMail);
}

int main(void)
{
    customer c[SIZE];
    customer temp;
    int exit=0,i=0;

    for(i=0;exit!=1&&i<10;i++) {
        c[i].ID=i;
        printf("Enter Name:\n");
        scanf("%s", c[i].Name);
        if(c[i].Name[0] != '-') {
            printf("Enter Adresse:\n");
            scanf("%s", c[i].Adresse);
            printf("Enter EMail:\n");
            scanf("%s", c[i].EMail);
        }else {
            exit=1;
            i--;
        }
    }

    for(int k = 0; k < i; k++) {
        for(int j = 0; j < i; j++) {
            if(strcmp(c[k].Name,c[j].Name)>0) {

                swap(&c[k], &temp);

                swap(&c[j], &c[k]);

                swap(&temp, &c[j]);
            }
        }
    }

    for(int j=0; j < i; j++) {
        printf("ID = %d\t Name = %s\tAdresse = %s\t Email = %s\t\n", c[j].ID,c[j].Name,c[j].Adresse,c[j].EMail);
    }
    return 0;
}
