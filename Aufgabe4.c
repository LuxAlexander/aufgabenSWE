#include <stdio.h>
#include <string.h>
/*Übungsaufgabe 1
 *Schreiben Sie ein C-Programm exchangeRateEUR2USDCalculator,
 *das zuerst einen Wechselkurs und dann einen Euro Betrag entgegennimmt.
 *Dann soll BenutzerInnen der Wert in US Dollar auf eine Nachkommastelle
 *genau angezeigt werden*/

/*Uebung 2 erweitert*/
int main(void) {
    float euro=0,kurs=0,money=0;
    char tocurrency[]={"USD"};

    printf("Wechselkurs Berechnung von Euro <-> USD!\n");
    printf("Bitte geben Sie einen Wechselkurs ein:\n");//Freundliche Benutzerausgabe, was zu tun ist, asume no airressistance, otherwise I would flush wrong input here and loop
    scanf("%f",&kurs);

    printf("Bitte geben Sie einen Betrag ein:\n");//euro betrag eingeben
    scanf("%f",&euro);

    printf("Geben sie 'EUR' oder 'USD' ein, je nachdem zu was sie wechseln moechten:");
    scanf("%s",&tocurrency);

    if(strcmp(tocurrency,"USD")==0) {
        money=kurs*euro;
    }else if(strcmp(tocurrency,"EUR")==0) {
        money=euro/kurs;
    }else {
        printf("No such currency");
    }
    printf("\nEingabe Betrag: %.2f entspricht bei einem Wechselkurs von %.3f -> %.1f %s",euro,kurs,money,tocurrency);//Ergebnis

    return 0;
}
