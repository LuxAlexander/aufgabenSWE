#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ============================================================================
 * Name : myBinarySearchTree.c
 * Author : Alexander Lux
 * Version : 1.0
 * Description : In/Post/PreOrder eines BinaryTree der X Elemente speichern soll und wählbare Elemente loescht
 * ============================================================================ */


typedef struct Node {
    int number;
    struct Node* left;
    struct Node* right;
} Node;

// Funktionen – bitte implementieren:
Node* createNode(int v) {
    Node* newNode =malloc(sizeof(Node));
    if(newNode != NULL) {
        newNode->number = v;
        newNode->left = NULL;
        newNode->right = NULL;
    } return newNode;
}

Node* deleteNode(Node* root, int);
// Fuegt eine Zahl in den binären Suchbaum ein
Node* insert(Node* root, int);

void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);

// Gibt den belegten Speicher des Baums wieder frei
void freeTree(Node* root);

Node* createTree(int);

int main() {

    Node* root = NULL;
    int anzahl=0,end=0;
    printf("Baum mit x Elementen Befuehlen. Bitte x eingeben\n");
    scanf("%d",&anzahl);
    if (anzahl!=0)root=createTree(anzahl);

    while (end!=9) {
        printf("1. InOrder\n2. PostOrder\n3. PreOrder \n4.New Element\n5.Delete\n 9.Exit\n");
        scanf("%d",&end);

        switch (end) {
            case 1:
                printf("Inorder:\n");
                inorder(root);
            break;
            case 2:
                printf("PostOrder:\n");
                postorder(root);
            break;
            case 3:
                printf("PreOrder:\n");
                preorder(root);
            break;
            case 4:
                printf("New Element:\n");
                scanf("%d",&anzahl);
                root=insert(root,anzahl);
            break;
            case 5:
                printf("Delete Element with Value?\n");
                scanf("%d",&anzahl);
                root=deleteNode(root,anzahl);
            break;
            case 9:
                freeTree(root);
        }
    }

    return 0;
}

Node* deleteNode(Node* root, int number) {
    Node* temp = NULL;
    if(root == NULL) {
        return NULL;
    }
    if (root->number > number)
        root->left = deleteNode(root->left, number);
    else if (root->number < number) {
        root->right = deleteNode(root->right, number);
    }else {
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }
        temp = temp->right;
        while (temp != NULL && temp->left != NULL) {
            temp = temp->left;
        }
        root->number = temp->number;
        root->right = deleteNode(root->right, temp->number);
    }

    return root;

}
// fuegt eine Zahl in den binären Suchbaum ein
Node* insert(Node* root, int number) {

    if(root == NULL) {
        Node* newNode = createNode(number);
        return newNode;
    } else {
        if(root->number > number ) {
                if(root->left == NULL) {
                    //Erstellt neuen Knoten und setzt left Pointer
                    //des aktuellen Knoten darauf
                    root->left = createNode(number);
                } else {
                    //Links vom aktuellen Knoten befindet sich
                    //bereits ein Knoten, deshalb muss in diese
                    //Richtung weiter gegangen werden.
                    //Rekursiver Aufruf, bei dem mit root->left
                    //"nach links" im Baum gegangen wird
                    insert(root->left,number);
                }
                //Einzufügende Wert ist größer als aktueller Knoten
                } else if(root->number < number) {
                    //Wenn sich rechts vom aktuellen Knoten kein
                    //weiterer mehr befindet (right == NULL),
                    //dann muss der neue Knoten rechts vom aktuellen
                    //eingefügt werden
                    if(root->right == NULL) {
                        //Erstellt neuen Knoten und setzt right Pointer
                        //des aktuellen Knoten darauf
                        root->right = createNode(number);
                    } else {
                            //Rechts vom aktuellen Knoten befindet sich
                            //bereits ein Knoten, deshalb muss in diese
                            //Richtung weiter gegangen werden.
                            //Rekursiver Aufruf, bei dem mit root->right
                            //"nach rechts" im Baum gegangen wird
                            insert(root->right,number);
                    }
                }
        }
    //Rückgabe des Wurzelknotens; durch rekursiven Aufruf
    //ist das der ursprüngliche Wurzelknoten des Bauems
    return root;
}

Node* createTree(int anzahl) {
    Node* root = NULL;
    int number=543;
    for (int i = 0; i < anzahl; i++) {
        printf("Enter a Number:\n");
        scanf("%d",&number);
        root = insert(root,number);
    }
    return root;
}
void preorder(Node* root) {
    if (root == NULL) {
        perror("No root");
        exit(1);
    }
    //Gibt den Wert des aktuellen Knotens aus
    printf("%d\n", root->number);
    //Wenn sich links ein Knoten befindet
    if(root->left != NULL)  {
        //dann wird "nach links gegangen"
        preorder(root->left);
    }
    //Wenn sich rechts ein Knoten befindet
    if(root->right != NULL) {
        //dann wird "nach rechts gegangen"
        preorder(root->right);
    }
}
// Gibt alle Wörter im Baum aus, die mit prefix beginnen
void inorder(Node* root) {
    if (root == NULL) {
        perror("No root");
        exit(1);
    }
    //Wenn sich links ein Knoten befindet
    if(root->left != NULL)  {
        //dann wird "nach links gegangen"
        inorder(root->left);
    }
    //Gibt den Wert des aktuellen Knotens aus
    printf("%d\n", root->number);
    //Wenn sich rechts ein Knoten befindet
    if(root->right != NULL) {
        //dann wird "nach rechts gegangen"
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if(root == NULL) {
        fprintf(stderr,"Root is NULL\n");
        exit(1);
    }
    if(root->left != NULL) {
        postorder(root->left);
    }
    if(root->right != NULL) {
        postorder(root->right);
    }
    printf("%d\n", root->number);
}

// Gibt den belegten Speicher des Baums wieder frei
void freeTree(Node* root) {
    if(root == NULL) {
        fprintf(stderr,"Root is NULL\n");
        exit(1);
    }
    if(root->left != NULL) {
        freeTree(root->left);
    }
    if(root->right != NULL) {
        freeTree(root->right);
    }
    printf("%d\n", root->number);
    free(root);
}