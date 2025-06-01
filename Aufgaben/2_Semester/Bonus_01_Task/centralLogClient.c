#include <winsock.h>
#include <string.h>
#include <stdio.h>

/* ============================================================================
 * Name : centralLogClient.c
 * Author : Alexander Lux
 * Version : 1.0
 * Description : Client sendet Vorgänge aus dem Produktionsbetrieb
 * ============================================================================ */

int main(int argc, char *argv[]) {
    WSADATA wd;
    WSAStartup(MAKEWORD(2, 0), &wd);  // Winsock initialisieren

    int sock = 0;
    struct sockaddr_in server;
    unsigned long addr;

    // Socket erstellen
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Fehler bei Erzeugung\n");
        return -1;
    }

    // Serveradresse vorbereiten
    memset(&server, 0, sizeof(server));
    addr = inet_addr("127.0.0.1");
    memcpy((char*) &server.sin_addr, &addr, sizeof(addr));
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    // Verbindung herstellen
    if (connect(sock, (struct sockaddr*) &server, sizeof(server)) < 0) {
        printf("Fehler bei Verbindungsaufbau\n");
        return -1;
    }

    printf("Verbindung hergestellt\n");
    char eingabe[100];
    while (strcmp(eingabe, "exit") != 0) {
        // Nachricht senden
        printf("Bitte Produktionsvorgang mitteilen.\n");
        scanf("%s", eingabe);
        send(sock, eingabe, sizeof(eingabe)-1, 0);
    }


    // Verbindung schließen (optional, aber empfohlen)
    closesocket(sock);
    WSACleanup();

    return 0;
}
