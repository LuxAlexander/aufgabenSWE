#include <stdio.h>
/*Übungsaufgabe 1
 *Schreiben Sie ein C-Programm exchangeRateEUR2USDCalculator,
 *das zuerst einen Wechselkurs und dann einen Euro Betrag entgegennimmt.
 *Dann soll BenutzerInnen der Wert in US Dollar auf eine Nachkommastelle
 *genau angezeigt werden*/

int main(void) {
    float euro=0,kurs=0,usd;

    printf("Wechselkurs Berechnung von Euro -> USD!\n");
    printf("Bitet geben Sie einen Wechselkurs ein:\n");//Freundliche Benutzerausgabe, was zu tun ist, asume no airressistance, otherwise I would flush wrong input here and loop
    scanf("%f",&kurs);

    printf("Bitte geben Sie einen EUR Betrag ein:\n");//euro betrag eingeben
    scanf("%f",&euro);

    usd = euro * kurs;//euro mal kurs ist usd

    printf("Der EUR Betrag %.2f entspricht bei einem Wechselkurs von %.3f, %.1f USD",euro,kurs,usd);//Ergebnis

    return 0;
}
