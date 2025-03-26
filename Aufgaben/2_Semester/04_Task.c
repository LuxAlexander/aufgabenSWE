#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ============================================================================
 * Name : visitorRegistry.c
 * Author : Alexander Lux
 * Version : 1.1
 * Description : Besucher Registrierung mit dynamischer Speicherverwaltung.
 * ============================================================================ */

typedef struct Visitor {
    char firstn[20];
    char lastn[20];
    char plz[6];  // Fixed: Changed from int[4] to char[6]
} Visitor;

void reallocate(Visitor**, int*);
void visit(Visitor*, int*);
void printall(Visitor*, int*);

void cut(char*);

int main(void) {
    Visitor *visitors = (Visitor*)calloc(1, sizeof(Visitor));
    int number = 0;
    int stop = 0;

    if (visitors == NULL) {
        fprintf(stderr, "Error in allocating memory for the visitors\n");
        exit(-1);
    }

    printf("Hello, welcome to our Ausstellung!\n");

    do {
        printf("Liste:1 || Neuer Besucher:2 || Beenden:3\n");
        scanf("%d", &stop);
        while (getchar() != '\n'); // Clear input buffer

        switch (stop) {
            case 1:
                printall(visitors, &number);
                break;
            case 2:
                reallocate(&visitors, &number);
                break;
            case 3:
                stop = 3;
                break;
            default:
                fprintf(stderr, "Bitte eine gültige Zahl eingeben.\n");
        }
    } while (stop != 3);

    free(visitors);
    return 0;
}

void reallocate(Visitor **visitors, int *number) {
    *number += 1;
    Visitor *temp = realloc(*visitors, (*number) * sizeof(Visitor));

    if (temp == NULL) {
        fprintf(stderr, "Konnte den Speicher nicht erweitern.\n");
        exit(-1);
    }

    *visitors = temp;  // Assign the reallocated memory back to the original pointer

    visit(*visitors, number);
}

void visit(Visitor *visitors, int *number) {
    int num = *number - 1;
    size_t len =0;
    if (visitors == NULL) {
        fprintf(stderr, "Fehler: Besucher existieren nicht.\n");
        return;
    }

    printf("Bitte Vornamen eingeben:\n");

    cut(visitors[num].firstn);

    printf("Bitte Nachnamen eingeben:\n");
    cut(visitors[num].lastn);

    printf("Bitte PLZ eingeben:\n");
    cut(visitors[num].plz);

    printf("Vorname: %s\tNachname: %s\tPLZ: %s\n Has been added.\n", visitors[num].firstn, visitors[num].lastn, visitors[num].plz);

    //printall(visitors, number);
}
void cut(char *string) {
    fgets(string, 20, stdin);
    size_t len = strlen(string);
    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';
    }
}

void printall(Visitor *visitors, int *number) {
    if (visitors != NULL) {
        for (int i = 0; i < *number; i++) {
            printf("Vorname: %s\tNachname: %s\tPLZ: %s\n", visitors[i].firstn, visitors[i].lastn, visitors[i].plz);
        }
    }
}
