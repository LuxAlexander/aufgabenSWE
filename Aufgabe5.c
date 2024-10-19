#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guess(int);

int main(void) {
    srand(time(NULL));
    int rnd=rand()%20;

    printf("Guess a number between 0 and 20\n");
    guess(rnd);

    return 0;
}
void guess(int rnd) {
    int guess=0;

    for(int i=1;i<=5;i++) {
        printf("Bitte Zahl raten:\n");
        scanf("%d",&guess);
        if(guess>rnd) {
            printf("Die gesuchte Zahl ist kleiner.\n");
        }else if(guess<rnd) {
            printf("Die gesuchte Zahl ist groesser.\n");
        }else {
            printf("Richtig geraten! Zahl ist %d\n",rnd);
            return;
        }
    }
}