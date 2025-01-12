#include <stdio.h>
#define maxlen 10
/* ============================================================================
 * Name : stack.c
 * Author : Alexander Lux
 * Version : 1.0
 * Description : Implement a Stack using a Array, include: push,pop,top,isEmpty,length,size,reset
 * ============================================================================ */

void push(int *,int);//new element on top
void pop(int*);//pops the top element from stack

void top();//looks at the current element

int isEmpty();//could be boolean

int length(int *);//current size
int size();//max size

void reset(int*);//clear elements

int main(void) {
    int stack[maxlen]={0};
    int element=0,choice=0;
    reset(stack);

    do {
        printf("What would you like to do?\n");
        printf("1. Push | 2. Pop | 3. Top | 4. CurrentSize | 5. MaxSize | 6. Reset | 7. Empty? | 8.Close\n");
        scanf("%d",&choice);

        switch(choice) {
            case 1: printf("Input element:\n");
                    scanf("%d",&element);
                    push(stack,element);
                    break;
            case 2: pop(stack);
                    break;
            case 3: top(stack);
                    break;
            case 4: printf("Current Array Size: %d\n",length(stack));
                    break;
            case 5: printf("Max Array Size: %d\n",size());
                    break;
            case 6: reset(stack);
                    break;
            case 7:
                    if(isEmpty(stack)==0) {
                        printf("Stack is not empty\n");
                    }else printf("Stack is empty\n");
                    break;
            case 8: printf("Have a nice day <3.\n");
                    break;
            default: printf("Invalid input\n");
        }
    }while(choice!=8);

    return 0;

}

void reset(int*stack) {
    for(int i=0;i<maxlen;i++) {
        stack[i]='/0';
    }
}
//Is Honestly more of a count function
int isEmpty(int*stack) {
    return length(stack)==0? 1:0;
}
int length(int*stack) {
    int n=0;
    for(int i=0;i<maxlen;i++) {
        if(stack[i]!='/0') {
            n++;
        }
    }
    return n;
}
int size() {
    return maxlen;
}

void push(int *stack, int element) {
    int position = length(stack);
    if (position < maxlen) {
        stack[position] = element;
        printf("Position: %d, new Element added: %d\n", position, element);
    } else {
        printf("Overflow. Cannot add element: %d\n", element);
    }
}


void pop(int*stack) {
    int position = length(stack) - 1; // Get index of top element
    if (position >= 0) {
        printf("Popped element: %d\n", stack[position]);
        stack[position] = 0; // Remove the top element
    } else {
        printf("Stack is empty, cannot pop.\n");
    }
}

void top(int*stack) {
    int position=length(stack)-1;
    if(position>=0) {
        printf("The top element is %d\n",stack[position]);
    }else printf("Stack is empty\n");

}