#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));

    float konto = rand(),einzahlung=0;
    char firstn[20],lastn[20];

    printf("Bitte Vornamen eingeben:\n");
    scanf("%s",firstn);

    printf("Bitte Nachnamen eingeben:\n");
    scanf("%s",lastn );

    printf("Guten Tag %s %s\n",lastn,firstn);

    printf("Bitte Einzahlungsbetrag eingeben:\n");
    scanf("%f",&einzahlung);

    printf("Bisheriger Kontostand %.2f\n",konto);
    konto+=einzahlung;
    printf("Neuer Kontostand %.2f\n",konto);

    return 0;
}
