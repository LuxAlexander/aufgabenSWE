#include <stdio.h>
#define len 20
/* ============================================================================
 * Name : StringFunctions.c
 * Author : Alexander Lux
 * Version : 1.0
 * Description : Combine String functions. + Aufgabe 14 ncat and strstr
 * ============================================================================ */
int stringcompare(char *arr1, char *arr2);
int count(char *);

void readStrings(char *,char *);
void copy(char *,char *);

void checkp(char *);

void stringappend(char *,char *);
void mystrncat (char *,char *);
char *mystrstr (char *,char *);

int main(void)
{
    char stringone[len*2]="",stringtocomp[len]="";//give first string more space
    printf("Programm to show String functions!\n");
    readStrings(stringone,stringtocomp);//Input 2 Strings

    printf("Check for substring: %s\n",mystrstr(stringone,stringtocomp));

    //Compare
    if(stringcompare(stringone,stringtocomp)==0) {
        printf("Strings are the same!\n");
    }else printf("%s and %s. Strings are different!\n",stringone,stringtocomp);

    //Override 2 with 1
    copy(stringone,stringtocomp);
    printf("%s and %s after Copy are now equal!\n",stringone,stringtocomp);

    //Append 2 on 1
    mystrncat(stringone,stringtocomp);//append x elements
    //stringappend(stringone,stringtocomp);//append
    printf("%s both Strings together.\n",stringone);

    //Check if the sum is a palindrom
    printf("Check if String is a palindrom:\n");
    checkp(stringone);

    return 0;
}
char *mystrstr (char *string, char *target) {
    int i=0;
    int lenstring=count(string),lentarget=count(target);
    if (!*target) {
        // Return the original string if the target is empty
        return string;
    }else if (lenstring<lentarget) {
        printf("Substring too big.\n",count(string),count(target));
        return NULL;
    }

    while(string[i]!='\0'){
        //Wenn the first character matches, check if the rest also matches
        if(string[i]==target[0]){
            for(int j=0;string[i+j]!='\0'&&string[i+j]==target[j];j++) {
                if(string[i+j]==target[lentarget-1]) {
                    printf("Found Substring %s in %s at Position %d\n",target,string,i+1);
                    return &string[i];
                }
            }
        }
        i++;
    }
}
void readStrings(char *stringone,char *stringtocomp) {
    int i=0;

    printf("Please enter the first string:\n");

    for(;i<=len && (stringone[i]=getchar())!='\n';i++);
    stringone[i]='\0';

    printf("Please enter the second string:\n");

    for(i=0;i<=len && (stringtocomp[i]=getchar())!='\n';i++);
    stringtocomp[i]='\0';

}
int count(char *arr){
    int i=0;
    while(arr[i]!='\0'){
        i++;
    }//String length
    return i;
}

int stringcompare(char *arr1, char *arr2){
    if(count(arr1)==count(arr2)){
        for(int i=0; i<count(arr1); i++){
            if(arr1[i]!=arr2[i]){
                return 1;//if something is different
            }
        }
    }else return 1;//if they don't match length

    return 0;//same
}

void copy(char arr1[], char arr2[]){
    for(int i=0; i<count(arr1); i++){
        arr2[i]=arr1[i];//might need a '/0' at last place but as long as it works
    }
}

void stringappend(char arr[],char arr2[]){
    int i=0;
    while(arr[i]!='\0'){
        i++;
    }//all of first string

    for(int j=0;j<count(arr2);j++){
        arr[i]=arr2[j];
        i++;
    }//all of second string
    arr[i]='\0';
}
void mystrncat(char arr[],char arr2[]){
    int i=0,n=0;

    while(arr[i]!='\0'){
        i++;
    }//all of first string
    printf("How many characters do you want to append:\n");
    scanf("%d",&n);

    for(int j=0;j<count(arr2)&&j<n;j++){
        arr[i]=arr2[j];
        i++;
    }//all of second string
    arr[i]='\0';

    printf("String combined:%s\n",arr);
}


void checkp(char arr[]){

    for(int i=0,j=count(arr)-1;i<count(arr);i++,j--){
        if(arr[i]!=arr[j]){
            printf("%s, is not a Palindrome\n",arr);
            return;
        }
    }

    printf("%s is a Palindrome\n",arr);
}