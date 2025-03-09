#include <stdio.h>
#include <string.h>
/*Übungsaufgabe 1
 *Schreiben Sie ein C-Programm exchangeRateEUR2USDCalculator,
 *das zuerst einen Wechselkurs und dann einen Euro Betrag entgegennimmt.
 *Dann soll BenutzerInnen der Wert in US Dollar auf eine Nachkommastelle
 *genau angezeigt werden*/

/*Uebung 2 erweitert*/
int main(void) {
    float inmoney=0,kurs=0,outmoney=0;
    char tocurrency[]={"USD"};

    printf("Wechselkurs Berechnung von Euro <-> USD!\n");
    printf("Bitte geben Sie den Euro->USD Wechselkurs ein:\n");//Freundliche Benutzerausgabe
    scanf("%f",&kurs);

    printf("Bitte geben Sie einen Betrag ein:\n");//betrag eingeben
    scanf("%f",&inmoney);

    printf("Geben sie 'EUR' oder 'USD' ein, je nachdem zu was sie wechseln moechten:");
    scanf("%s",&tocurrency);

    if(strcmp(tocurrency,"USD")==0) {
        outmoney=kurs*inmoney;
    }else if(strcmp(tocurrency,"EUR")==0) {
        outmoney=inmoney/kurs;
    }else {
        printf("No such currency");
    }
    printf("\nEingabe Betrag: %.2f entspricht bei einem Wechselkurs von %.3f -> %.1f %s",inmoney,kurs,outmoney,tocurrency);//Ergebnis

    return 0;
}
