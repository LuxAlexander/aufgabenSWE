#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STOCK 3
/* ============================================================================
 * Name : secondhandVinylStore.c
 * Author : Alexander Lux
 * Version : 1.0
 * Description : Aufgabe 01_2Semester, Regal Verwaltungs simulation, using a struct Alben (Interpret, Titel, VÖ-Jahr, Zustand)
 * Suche nach Interpreten oder Titeln, year before/after. Sort VÖ Jahr oder alphabetisch nach Interpret.
 * ============================================================================ */

typedef struct Alben {
    char interpret[50];//string or two
    char titel[50];//Is a string
    int year;//number is like 1980
    int zustand; //Say from 1 to 10 how good the condition is.
}Alben;

void searchstring(char*,int,Alben*);

void display(int,Alben*);
void printData(Alben);

void fillregal(Alben*);

int yearup(int j,Alben *);
int compdown(const void *, const void *);

int compare_interprets(const void *a,const void *b);
int compare_interpretsdown(const void *a,const void *b);

int main(void) {
    Alben regal[10];
    int go=10,searchint=0;
    char inputstring[51];


    fillregal(regal);

    do {
        printf("What do you want to do? (0: Leave, 1:search, 2 Sort)\n");
        scanf("%d",&go);

        switch(go) {
            case 0: printf("Have a nice day.");break;
            case 1:
                    printf("Search by Interpret:1, Titel:2, Before year:3 or after year:4\n");
                    scanf("%d",&searchint);
                    if (searchint<5) {
                        printf("Geben sie den Gewuenschten String ein.\n");
                        fflush(stdin);//Clear the standard input

                        fgets(inputstring,51,stdin);
                        inputstring[strcspn(inputstring, "\n")] = 0;  // Removes trailing newline

                        searchstring(inputstring, searchint, regal);
                    }
                    break;
            case 2: printf("Wie soll sortiert werden? (1:Interpret Auf, 2: Interpret ab, 3: Year Aufsteigend, 4: Absteigend)\n");
                    scanf("%d",&searchint);

                    display(searchint, regal);

            break;
            default: printf("a ist irgendwas\n"); break;
        }

    }while (go>0);

    return 0;
}

int swap(int j,Alben *regal) {
    Alben temp;

    strcpy(temp.interpret,regal[j].interpret);
    strcpy(temp.titel,regal[j].titel);
    temp.year = regal[j].year;
    temp.zustand = regal[j].zustand;

    strcpy(regal[j].interpret,regal[j+1].interpret);
    strcpy(regal[j].titel,regal[j+1].titel);
    regal[j].year=regal[j+1].year;
    regal[j].zustand=regal[j+1].zustand;

    strcpy(regal[j+1].interpret,temp.interpret);
    strcpy(regal[j+1].titel,temp.titel);
    regal[j+1].year=temp.year;
    regal[j+1].zustand=temp.zustand;

}

int compare_interprets(const void *a, const void *b) {
    const Alben *album_a = (const Alben *)a;
    const Alben *album_b = (const Alben *)b;
    return strcmp(album_a->interpret, album_b->interpret);
}

int compare_interpretsdown(const void *a, const void *b) {
    const Alben *album_a = (const Alben *)a;
    const Alben *album_b = (const Alben *)b;
    return strcmp(album_b->interpret, album_a->interpret);
}


void display(int modus, Alben regal[]) {
    for (int i = 0; i < STOCK - 1; i++) {
        for (int j = 0; j < STOCK - i - 1; j++) {
            if (modus == 1) {
                qsort (regal, STOCK, sizeof(*regal), compare_interprets);
            }else if (modus == 2) {
                qsort (regal, STOCK, sizeof(*regal), compare_interpretsdown);
            }else if (modus == 3) {
                if (regal[j].year > regal[j + 1].year) {
                    swap(j,regal);
                }
            }else if (modus == 4) {
                if (regal[j].year < regal[j + 1].year) {
                    swap(j,regal);
                }
            }
        }
    }

    for (int i = 0 ; i < STOCK ; i++) {
        printData(regal[i]);
    }

}

void fillregal(Alben regal[]){
    strcpy(regal[0].interpret, "Blexander Lux");
    strcpy(regal[0].titel, "Apass und Freude");
    regal[0].year =2003;
    regal[0].zustand =-10;

    strcpy(regal[1].interpret, "Alexander Lux");
    strcpy(regal[1].titel, "Bpass und Freude");
    regal[1].year =2004;
    regal[1].zustand =10;

    strcpy(regal[2].interpret, "Clexander Lux");
    strcpy(regal[2].titel, "Xpass und Freude");
    regal[2].year =2002;
    regal[2].zustand =10;
}

void printData(Alben data) {
    printf("Interpret: %s\n",data.interpret);
    printf("Titel: %s\n",data.titel);
    printf("Year: %d\n",data.year);
    printf("Zustand: %d\n",data.zustand);
}

void searchstring(char* string, int modus, Alben regal[]) {
    printf("Searching\n");

    for (int i = 0; i<STOCK;  i++) {

        switch (modus) {
            case 1:
                if (strcmp(string, regal[i].interpret) == 0) {
                    printData(regal[i]);
                }
                break;
            case 2:
                if (strcmp(string, regal[i].titel) == 0) {
                    printData(regal[i]);
                }
                break;
            case 3:
                if (regal[i].year < atoi(string)) {
                    printData(regal[i]);
                }
                break;
            case 4:
                if (regal[i].year > atoi(string)) {
                    printData(regal[i]);
                }
                break;
            default:
                printf("No such search defined.\n");
        }


    }
}