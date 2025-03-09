#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ============================================================================
 * Name : secondhandVinylStoreWithFiles.c
 * Author : Alexander Lux
 * Version : 1.0
 * Description : Aufgabe 01_2Semester, Regal Verwaltungs simulation, using a struct Alben (Interpret, Titel, VÖ-Jahr, Zustand)
 * Suche nach Interpreten oder Titeln, year before/after. Sort VÖ Jahr oder alphabetisch nach Interpret.
 * + Aufgabe 02 save Alben in Files and add new Alben
 * ============================================================================ */



typedef struct Alben {
    char interpret[50];//string or two
    char titel[50];//Is a string
    int year;//number is like 1980
    int zustand; //Say from 1 to 10 how good the condition is.
}Alben;

void searchstring(char*,int,Alben*,int*);

void display(int,Alben*,int*);
void printData(Alben);

void fillregal(Alben*,int*);

int compare_interprets(const void *a,const void *b);
int compare_interpretsdown(const void *a,const void *b);

int addnewAlbum(Alben*,int*);

int main(void) {
    Alben regal[10];
    int go=10,searchint=0;
    char inputstring[51];
    int stock=0;

    fillregal(regal,&stock);

    do {
        printf("What do you want to do? (0: Leave, 1:search, 2 Sort,3 Add new Alben)\n");
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

                        searchstring(inputstring, searchint, regal,&stock);
                    }
                    break;
            case 2: printf("Wie soll sortiert werden? (1:Interpret Auf, 2: Interpret ab, 3: Year Aufsteigend, 4: Absteigend)\n");
                    scanf("%d",&searchint);

                    display(searchint, regal,&stock);

                    break;
            case 3:
                    addnewAlbum(regal,&stock);
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


void display(int modus, Alben regal[],int*stock) {
    if (modus == 1) {
        qsort (regal, *stock, sizeof(*regal), compare_interprets);
    }else if (modus == 2) {
        qsort (regal, *stock, sizeof(*regal), compare_interpretsdown);
    }else {
        for (int i = 0; i < *stock-1; i++) {
            for (int j = 0; j < *stock - i-1; j++) {

                if (modus == 3) {
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
    }

    for (int i = 0 ; i < *stock ; i++) {
        printData(regal[i]);
    }

}
int addnewAlbum(Alben regal[],int*stock) {
    FILE *fptr=NULL;


    fptr=fopen("..\\regal.txt","ab");
    if (fptr!=NULL&&*stock<=10) {
        printf("%d\n",*stock);

        printf("Adding new Album: \n");

        printf("Interpret:\n");
        fflush(stdin);//Clear the standard input

        fgets(regal[*stock].interpret,51,stdin);
        regal[*stock].interpret[strcspn(regal[*stock].interpret, "\n")] = 0;

        printf("Titel:\n");
        fflush(stdin);//Clear the standard input

        fgets(regal[*stock].titel,51,stdin);
        regal[*stock].titel[strcspn(regal[*stock].titel, "\n")] = 0;

        printf("Year:\n");
        scanf("%d",&regal[*stock].year);
        printf("Zustand:\n");
        scanf("%d",&regal[*stock].zustand);

        printData(regal[*stock]);
        fwrite(&regal[*stock],sizeof(Alben),1,fptr);
        *stock +=1;
        fclose(fptr);
    }else printf("Error\n");


}

void fillregal(Alben regal[],int *stock){
    FILE *fptr=NULL;
    int i=0;
    fptr=fopen("..\\regal.txt","rb");

    if (fptr!=NULL) {

        *stock = fread(regal, sizeof(struct Alben), 10, fptr);
        for (int i=0; i<*stock; i++) {
            printData(regal[i]);
        }
        fclose(fptr);

    }else {
        fptr=fopen("..\\regal.txt","wb");

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

        *stock=2;
        fwrite(regal,sizeof(Alben),*stock,fptr);
        fclose(fptr);
    }


}

void printData(Alben data) {
    printf("Interpret: %s\n",data.interpret);
    printf("Titel: %s\n",data.titel);
    printf("Year: %d\n",data.year);
    printf("Zustand: %d\n",data.zustand);
}

void searchstring(char* string, int modus, Alben regal[],int* stock) {
    printf("Searching\n");

    for (int i = 0; i<*stock;  i++) {

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