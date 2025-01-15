#include <stdio.h>

void copy(char[], char[]);
void printbackwards(char[]);

int count(char[]);
int countchar(char [],char );
int countvocal(char[]);
void countall(char[]);

int stringcompare(char[], char[]);
void stringadd(char[], char[]);

void up(char[]);
void down(char[]);

void checkp(char[]);

void delchar(char[], char);
void changechar(char[], char, char);

int main(){
    char name[20]="", name2[20]="Tim";
    int len=0;
    printf("Geben Sie Ihren Namen ein: \n");
    scanf("%s", name);

    printf("Hallo %s\n", name);

    printf("Die Laenge des Namens betraegt %d\n", count(name));
    printf("Second String is %s\n", name2);
    printf("String Compare: %s \n",stringcompare(name, name2)? "false" : "true");
    /*copy(name, name2);
    printf("Second String after copy is %s\n", name2);
    printf("String Compare: %s \n",stringcompare(name, name2)? "false" : "true");*/

    stringadd(name, name2);

    printf("String after add is %s\n", name);
    up(name);
    //printbackwards(name);
    printf("M in name is %d\n", countchar(name, 'M'));
    changechar(name, 'M', 'm');
    printf("String after delete is %s\n", name);

    //countall(name);
    checkp(name);
    return 0;
}

void checkp(char arr[]){
    
    for(int i=0,j=count(arr)-1;i<count(arr);i++,j--){
       if(arr[i]!=arr[j]){
           printf("Not a Palindrome\n");
           return;
       }
    }
    printf("Palindrome\n");
}
void up(char arr[]){
   for(int i=0;i<count(arr);i++){
       if(arr[i]>='a' && arr[i]<='z'){
           arr[i]=arr[i]-32;
       }
   }
}

void down(char arr[]){
   for(int i=0;i<count(arr);i++){
       if(arr[i]>='A' && arr[i]<='Z'){
           arr[i]=arr[i]+32;
       }
   }
}

void delchar(char arr[], char ident){
    int i=0;
    while(arr[i]!='\0'){
        if(arr[i]==ident){
            for(int j=i;j<count(arr);j++){
                arr[j]=arr[j+1];
            }
        }
        i++;
    }
}
void changechar(char arr[], char ident, char change){
    int i=0;
    while(arr[i]!='\0'){
        if(arr[i]==ident){
            arr[i]=change;
        }
        i++;
    }
}
void printbackwards(char arr[]){
    for(int i=count(arr)-1;i>=0;i--){
        printf("%c", arr[i]);
    }
}

int count(char arr[]){
    int i=0;
    while(arr[i]!='\0'){
        i++;
    }
    return i;
}


int countvocal(char arr[]){
    int i=0,count=0;
    while(arr[i]!='\0'){
        if(arr[i]=='a' || arr[i]=='e' || arr[i]=='i' || arr[i]=='o' || arr[i]=='u'){
            count++;
        }
        i++;
    }
    return count;
}

void copy(char arr1[], char arr2[]){
    for(int i=0; i<count(arr1); i++){
        arr2[i]=arr1[i];
    }
}

int stringcompare(char arr1[], char arr2[]){
    if(count(arr1)==count(arr2)){
        for(int i=0; i<count(arr1); i++){
            if(arr1[i]!=arr2[i]){
                return 1;
            }
        } 
    }else return 1;

    return 0;
}

void stringadd(char arr[],char arr2[]){
    int i=0;
    while(arr[i]!='\0'){
        i++;
    }
    for(int j=0;j<count(arr2);j++){
        arr[i]=arr2[j];
        i++;
    }
    arr[i]='\0';
}

int countchar(char arr[],char ident){
    int counter=0;
    for(int i=0;i<count(arr);i++){
        if(arr[i]==ident){
            counter++;
        }
    }
    return counter;
}

void countall(char arr[]){
    int counter=0;
    char check='A';
    for (int j=0;j<26;j++,check++)
    {
        printf("Checking for %c\n", check);
        counter=0;
        
        counter+=countchar(arr, check);
        
        printf("counted %d.\n",counter);
    }
}

