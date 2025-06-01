#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <string.h>
#include <time.h>

/* ============================================================================
* Name : centralLogServer.c
 * Author : Alexander Lux
 * Version : 1.0
 * Description : Save Data into file with (Datum, Uhrzeit, Sender-IP)
 * ============================================================================ */

int main(void) {
    WSADATA wd;
    WSAStartup(MAKEWORD(2, 0), &wd);  // Winsock initialisieren

    int serversock, clientsock;
    struct sockaddr_in server;
    struct sockaddr_in client;
    int len = sizeof(client);

    // Server-Socket erstellen
    serversock = socket(AF_INET, SOCK_STREAM, 0);
    if (serversock < 0) {
        printf("Fehler bei der Socketerstellung\n");
        return -1;
    }

    // Server-Adresse konfigurieren
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(8080);

    // Socket binden
    if (bind(serversock, (struct sockaddr*) &server, sizeof(server)) < 0) {
        printf("Fehler beim Binding\n");
        return -1;
    }

    // Auf eingehende Verbindungen hören
    if (listen(serversock, 5) < 0) {
        printf("Fehler beim Listening\n");
        return -1;
    }

    printf("Server: Warten auf neue Verbindung...\n");

    // Verbindung akzeptieren
    clientsock = accept(serversock, (struct sockaddr*) &client, &len);
    if (clientsock < 0) {
        printf("Fehler beim Accepting\n");
        return -1;
    }

    printf("Server: Verbindung akzeptiert\n");
    time_t now = time(NULL);
    char *client_ip = inet_ntoa(client.sin_addr);  // aus accept()
    FILE *file = fopen("log.txt", "a");  // "a" für Anhängen

    // Daten empfangen
    char data[100] = {0};
    while (strcmp(data, "exit") != 0) {
        struct tm *t = localtime(&now);
        recv(clientsock, data, sizeof(data) - 1, 0);  // -1 für Null-Terminierung
        printf("Server: Empfangen: %s\n", data);
        if (file) {
            fprintf(file, "[%04d-%02d-%02d %02d:%02d:%02d] IP: %s, Nachricht: %s\n",
                t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
                t->tm_hour, t->tm_min, t->tm_sec,
                client_ip, data);
        }
    }



    // Verbindungen schließen und aufräumen
    fclose(file);
    closesocket(clientsock);
    closesocket(serversock);
    WSACleanup();

    return 0;
}
