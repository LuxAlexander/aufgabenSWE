#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ============================================================================
 * Name : accountingTool.c
 * Author : Alexander Lux
 * Version : 1.0
 * Description : Double Linked List + header, Buchungssätze (Soll, Haben, Text, Betrag), Flow Chart, kommaseparierten Datei,
 * Pfad und Namen als Kommandozeilenparameter. Tasks: new Nodes, printAll, search for, printAllwithKonto, delete node element x, safe into file
 * ============================================================================ */

typedef struct Buchungssaetze{
    char soll[5];
    char haben[5];
    char text[32];
    float betrag;
}Data;

typedef struct Node {
    Data data;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct Header {
    int cnt;
    struct Node* first;
    struct Node* last;
}Header;

Header* createHeader();
void addNode(Header*, Node*);
void readData(FILE* fptr, Header* head);
void printAll(Header*);

void searchText(Header*, char*);
void searchKonto(Header*, char*);
void deleteNodeX(Header*, int);

void safeAll(Header*);
void freeall(Header* head);

int main(int argc, const char * argv[]) {
    FILE *fptr=NULL;
    Header* head=createHeader();
    Node* node=NULL;
    int choice=10;
    if(argc < 2) {
        fprintf(stderr,"Not enough arguments\n");
        exit(EXIT_FAILURE);
    }
    fptr = fopen(argv[1],"r");//If I already enter the path, it would be ineffecient to also write the filename
    //fptr = fopen(strcat(argv[1],argv[2]),"w");


    while (choice != 0) {
        printf("Finish:[0],Read Data:[1],Search for Text:[2],Search for Konto:[3],printAll:[4],deleteNodeX:[5],safeAll:[6]\n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                readData(fptr,head);
                break;
            case 2:
                printf("Input search phrase\n");
                char search[100];
                scanf("%s",search);
                searchText(head,search);
                break;
            case 3:
                printf("Input search Konot\n");
                char konto[100];
                scanf("%s",konto);
                searchKonto(head,konto);
                break;
            case 4:
                printAll(head);
                break;
            case 5:
                printf("Input what node to delete\n");
                int x=200;
                scanf("%d",&x);
                deleteNodeX(head,x);
                break;
            case 6:
                safeAll(head);
                break;
            case 0:
                printf("bye bye");
                break;
            default:
                printf("Wrong choice\n");

        }

    }


    freeall(head);
    return 0;
}

Header* createHeader() {
    Header* head = (Header*)malloc(sizeof(Header));
    if (head!=NULL) {
        head->cnt = 0;
        head->first = NULL;
        head->last = NULL;
    }
    return head;
}
void readData(FILE* fptr, Header* head) {

    if(fptr==NULL||head==NULL) {
        fprintf(stderr,"Error opening file\n");
        exit(EXIT_FAILURE);
    }
    Node* node=head->first;
    char* temp=NULL;
    char line[100];
    while(fgets(line, 100, fptr )!= NULL) {
        if(node==NULL) {
            node=malloc(sizeof(Node));
        }
        temp=strtok(line, ",");
        strcpy(node->data.soll,temp);

        temp=strtok(NULL, ",");
        strcpy(node->data.haben,temp);

        temp=strtok(NULL, ",");
        strcpy(node->data.text,temp);

        temp=strtok(NULL, ",");
        node->data.betrag=atof(temp);

        //Take care on the string since it could potentially suck up the comma
        addNode(head,node);
        node->next=NULL;
        node=node->next;
    }
    fclose(fptr);
}
void addNode(Header* list, Node* data) {
    if (list==NULL||data==NULL) {
        return;
    }
    if (list->first==NULL) {
        list->first = data;
        list->last = data;
    }else {
        data->prev = list->last;
        list->last->next = data;
        list->last = data;
    }
    list->cnt++;

}

void searchText(Header* head, char *text) {
    if (head==NULL) {
        fprintf(stderr,"Empty file\n");
        exit(EXIT_FAILURE);
    }else if (text == NULL) {
        printAll(head);
    }
    Node* temp = head->first;
    printf("Searching:\n\n");
    while (temp!=NULL) {
        if (strcmp(temp->data.text,text)==0) {
            printf("Soll:%s \t Haben:%s \t Text:%s \t Betrag:%.2f\n",temp->data.soll,temp->data.haben,temp->data.text,temp->data.betrag);
            return;
        }
        temp = temp->next;
    }
    printf("No matching Text found\n\n");

}

void searchKonto(Header* head, char *text) {
    if (head==NULL) {
        fprintf(stderr,"Empty file\n");
        exit(EXIT_FAILURE);
    }else if (text == NULL) {
        printAll(head);
    }
    Node* temp = head->first;
    printf("Searching for Konto:\n\n");
    while (temp!=NULL) {
        if (strcmp(temp->data.soll,text)==0 || strcmp(temp->data.haben,text)==0) {
            printf("Soll:%s \t Haben:%s \t Text:%s \t Betrag:%.2f\n\n",temp->data.soll,temp->data.haben,temp->data.text,temp->data.betrag);
        }
        temp = temp->next;
    }
}

void printAll(Header* list) {
    if (list==NULL) {
        return;
    }
    Node* temp = list->first;
    printf("Print List:\n\n");
    while (temp!=NULL) {
        printf("Soll:%s \t Haben:%s \t Text:%s \t Betrag:%.2f\n",temp->data.soll,temp->data.haben,temp->data.text,temp->data.betrag);
        temp = temp->next;
    }
}
void safeAll(Header* head) {
    char line[100]=" ";
    printf("Where to save to?");
    scanf("%s",line);

    FILE* fptr=fopen(line,"w");

    if(fptr==NULL) {
        fprintf(stderr,"Error creating file\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = head->first;
    while (temp!=NULL) {
        printf("Writing to file\n");
        fprintf(fptr,"%s, %s, %s, %f\n", temp->data.soll, temp->data.haben, temp->data.text, temp->data.betrag);
        temp = temp->next;
    }
    fclose(fptr);

}
void deleteNodeX(Header* head, int x) {
    if (head == NULL) {
        fprintf(stderr, "No head\n");
        exit(EXIT_FAILURE);
    } else if (head->cnt < x) {
        fprintf(stderr, "Not enough data\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = head->first;
    Node* prev = NULL;
    int i = 1;
    while (temp != NULL) {
        if (i == x) {
            printf("Node will be deleted\n");
            if (prev != NULL) {
                prev->next = temp->next;
            } else {//First node
                head->first = temp->next;
                if (head->first != NULL) {
                    head->first->prev = NULL;
                }
            }

            if (temp->next != NULL && temp->next->prev != NULL) {
                temp->next->prev = prev;
            }

            free(temp);
            head->cnt--;
            return;
        }
        i++;
        prev = temp;
        temp = temp->next;
    }
    printf("No matching node found\n\n");
}

void freeall(Header* head) {
    Node* temp = head->first;
    Node* prev = NULL;
    while (temp!=NULL) {
        prev = temp;
        temp = temp->next;
        free(prev);
    }
    free(head);
}