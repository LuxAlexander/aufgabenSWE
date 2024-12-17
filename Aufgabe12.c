#include <stdio.h>

/* ============================================================================
 * Name : PalindromCheck.c
 * Author : Alexander Lux
 * Version : 1.0
 * Description : Checks if a String is a palindrom.
 * ============================================================================ */


int main(void) {
    char tocheck[20]="";
    int count=0;

    printf("Enter a string to check if it's a palindrom:\n");
    scanf("%s",tocheck);

    while(tocheck[count]!='\0'){
        count++;
    }//Could use the string function that gives me the length or go to the end, while checking a flipped string.

    //don't check to terminition character at the last positon
    //i goes up the array, while j goes down and they meet in the middle
    for(int i=0,j=count-1;i<=j;i++,j--){
        if(tocheck[i]!=tocheck[j]){
            printf("%s is not a Palindrome (Note that upper/lower case need to match)\n", tocheck);
            return 0;
        }
    }
    printf("%s is a Palindrome\n",tocheck);

    return 0;
}
