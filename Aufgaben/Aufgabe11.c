#include <stdio.h>
#include <string.h>
#define fname "alex"
#define lname "lux"
#define lnumber 357

/* ============================================================================
 * Name : TicketWinner.c
 * Author : Alexander Lux
 * Version : 1.0
 * Description : Enter Name and Number and find out if you won the lottery.
 * ============================================================================ */

int main(void) {
    char firstname[20]="",lastname[20]="";
    int luckynumber=0;

    printf("Enter your first name and last name:");
    scanf("%s %s",firstname,lastname);

    printf("Enter your lucky number:");
    scanf("%d",&luckynumber);

    //use strcmp to compare strings or check every position of the array against each other
    if(luckynumber==lnumber&&strcmp(firstname,fname)==0&&strcmp(lastname,lname)==0) {
        printf("You are the winner\n");
    }else printf("Chance to win was low anyway, don't mind it.\n");
    return 0;
}
