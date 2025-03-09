#include <stdio.h>
#define maxlen 10
/* ============================================================================
 * Name : queue.c
 * Author : Alexander Lux
 * Version : 1.0
 * Description : Implement a queue using a Array, include: enq,deq,first,isEmpty,length,size,reset
 * ============================================================================ */

int enqueue(int *,int,int);//new element on top
int dequeue(int*,int);//pops the top element from stack

int first(int*,int);//looks at the current element

int isEmpty();//could be boolean

int length(int *);//current size
int size();//max size

void reset(int*);//clear elements

int main(void)
{
    int queue[maxlen]={0};
    int positionlast=-1;
    int positionfirst=0;
    int element=500;

    reset(queue);
    dequeue(queue,positionfirst);//Check if dequeue from empty

    for(int i=0;i<maxlen+5;i++) {
        printf("\nAdd %d.", i);
        positionlast=enqueue(queue,i,positionlast);
    }//Fill array and check if it goes over the boundaries/Overflow

    positionfirst=dequeue(queue,positionfirst);//take one item from queue

    for(int i=0;i<=length(queue);i++) {
        printf("%d\n",queue[i]);
    }//print all

    positionfirst=dequeue(queue,positionfirst);//take another item
    element=first(queue,positionfirst);

    if(element!='\0') {
        printf("First in Queue is: %d\n",element);//print new first in line
    }else printf("Positon of the element is NULL.\n");

    positionlast=enqueue(queue,12,positionlast);//new item added to last place
    printf("Last in Queue is: %d\n",queue[positionlast]);

    positionlast=enqueue(queue,13,positionlast);
    positionlast=enqueue(queue,14,positionlast);

    for(int i=0;i<=length(queue);i++) {
        printf("%d\n",queue[i]);
    }

    return 0;
}
int first(int*queue,int positionfirst) {
    if(isEmpty(queue)!=1) {
        return queue[positionfirst];
    }
    printf("queue is empty.\n");
}
int dequeue(int* queue, int position) {
    if(isEmpty(queue)!=1) {
        queue[position]='\0';
        return (position+1)%maxlen;
    }
    printf("Couldn't dequeue because queue is empty.\n");
}
int enqueue(int*queue,int element,int pos) {

    if(length(queue)<size()) {
        if(pos<size()-1) {
            queue[pos+1]=element;
        }else {
            queue[0]=element;
        }
        return pos+1;
    }
    printf("Element not enqueued.Size problem\n");
    return -1;
}
void reset(int*queue){
    for(int i=0;i<maxlen;i++) {
        queue[i]='\0';
    }
}
int size(){
    return maxlen;
}
int isEmpty(int*queue) {
    return length(queue)==0? 1:0;
}

int length(int*queue) {
    int n=0;
    for(int i=0;i<maxlen;i++) {
        if(queue[i]!='\0') {
            n++;
        }
    }
    return n;
}