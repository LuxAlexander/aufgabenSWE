#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Piece {
    char bezeichnung[10];
    float cost;
    int stueck;
    struct Piece *nextPiece;
} Piece;

Piece* addPiece(Piece *);
Piece* addPieceAfterV(Piece *, char*);
void freeAfterV(Piece *, char*);
void freeLast(Piece **);
void freeAll(Piece *);

int main(void) {
    Piece *root = NULL;

    root = addPiece(root);

    printf("Piece:\nBez: %s\nCost: %.2f\nStueck: %d\n", root->bezeichnung, root->cost, root->stueck);

    root = addPiece(root);
    printf("Piece:\nBez: %s\nCost: %.2f\nStueck: %d\n", root->nextPiece->bezeichnung, root->nextPiece->cost, root->nextPiece->stueck);

    addPieceAfterV(root, root->bezeichnung);

    printf("All PIECES:\n");
    for (Piece *temp = root; temp != NULL; temp = temp->nextPiece) {
        printf("Piece:\nBez: %s\nCost: %.2f\nStueck: %d\n", temp->bezeichnung, temp->cost, temp->stueck);
    }

    freeAfterV(root, root->bezeichnung);

    printf("After freeAfterV:\n");
    for (Piece *temp = root; temp != NULL; temp = temp->nextPiece) {
        printf("Piece:\nBez: %s\nCost: %.2f\nStueck: %d\n", temp->bezeichnung, temp->cost, temp->stueck);
    }

    freeAll(root);
    return 0;
}

Piece* addPiece(Piece *piece) {
    Piece *temp = piece;
    while (temp && temp->nextPiece) temp = temp->nextPiece;

    Piece *newPiece = (Piece *)malloc(sizeof(Piece));
    if (!newPiece) {
        fprintf(stderr, "Out of memory\n");
        exit(EXIT_FAILURE);
    }

    printf("Adding piece:\nBezeichnung: ");
    if (!fgets(newPiece->bezeichnung, sizeof(newPiece->bezeichnung), stdin)) {
        free(newPiece);
        return piece;
    }
    newPiece->bezeichnung[strcspn(newPiece->bezeichnung, "\n")] = '\0';

    printf("Cost: ");
    if (scanf("%f", &newPiece->cost) != 1) {
        free(newPiece);
        return piece;
    }
    printf("Stueck: ");
    if (scanf("%d", &newPiece->stueck) != 1) {
        free(newPiece);
        return piece;
    }
    while (getchar() != '\n'); // Clear input buffer

    newPiece->nextPiece = NULL;
    if (temp) temp->nextPiece = newPiece;
    return piece ? piece : newPiece;
}

Piece* addPieceAfterV(Piece *piece, char *v) {
    for (Piece *temp = piece; temp; temp = temp->nextPiece) {
        if (strcmp(temp->bezeichnung, v) == 0) {
            Piece *newPiece = (Piece *)malloc(sizeof(Piece));
            if (!newPiece) {
                fprintf(stderr, "Out of memory\n");
                exit(EXIT_FAILURE);
            }

            printf("Adding piece:\nBezeichnung: ");
            fgets(newPiece->bezeichnung, sizeof(newPiece->bezeichnung), stdin);
            newPiece->bezeichnung[strcspn(newPiece->bezeichnung, "\n")] = '\0';

            printf("Cost: ");
            scanf("%f", &newPiece->cost);
            printf("Stueck: ");
            scanf("%d", &newPiece->stueck);
            while (getchar() != '\n');

            newPiece->nextPiece = temp->nextPiece;
            temp->nextPiece = newPiece;
            return piece;
        }
    }
    printf("Element '%s' not found in the list.\n", v);
    return piece;
}

void freeAll(Piece *root) {
    while (root != NULL) {
        Piece* temp = root;        // Store current node
        root = root->nextPiece; // Move to next node
        free(temp);         // Free the stored node
    }
}

void freeLast(Piece **root) {
    if (!*root) return;

    if (!(*root)->nextPiece) {
        free(*root);
        *root = NULL;
        return;
    }

    Piece *temp = *root;
    while (temp->nextPiece && temp->nextPiece->nextPiece)
        temp = temp->nextPiece;

    free(temp->nextPiece);
    temp->nextPiece = NULL;
}

void freeAfterV(Piece *root, char *v) {
    for (Piece *temp = root; temp && temp->nextPiece; temp = temp->nextPiece) {
        if (strcmp(temp->bezeichnung, v) == 0) {
            Piece *toFree = temp->nextPiece;
            if (toFree) {
                temp->nextPiece = toFree->nextPiece;
                free(toFree);
            }
            return;
        }
    }
}