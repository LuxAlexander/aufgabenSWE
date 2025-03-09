#include <stdio.h>
#define len 20
int main(void) {
    char input[len]={},tocopy[len]="Secret";
    printf("Please enter a string:\n");
    scanf("%s",input);

    for(int i=0;input[i]!='\0';i++) {
        tocopy[i]=input[i];
    }

    printf("String 1: %s\n",input);
    printf("String 2: %s\n",tocopy);

    return 0;
}
