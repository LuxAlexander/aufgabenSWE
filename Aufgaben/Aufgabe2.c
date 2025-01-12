#include <stdio.h>

void namesinput(char str[],int);

int main(void) {
    struct person{
        char firstn[20];
        char lastn[20];
    };
    struct person persons[3];

    for(int i = 0; i < 3; i++) {
        namesinput(persons[i].firstn,0);
        namesinput(persons[i].lastn,1);
    }

    for(int i = 0; i < 3; i++) {
        printf("%s %s \n",persons[i].lastn, persons[i].firstn);
    }
    return 0;
}

void namesinput(char strg[],int ident) {
    if(ident ==0) {
         printf("Enter a first-name:\n");
    }else printf("Enter a last-name:\n");

    scanf("%s",strg);
}