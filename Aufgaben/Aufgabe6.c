#include <stdio.h>

int main(void) {
    float sum=0,time=1,i=0;

    for(;i<=10&&time!=0;i++) {
        printf("Bitte Produktionszeit eingeben:");
        scanf("%f",&time);
        sum+=time;
        if(time==0)i--;
    }

    printf("Die mittlere Produktionszeit ist %.2f. Sum: %.2f Times:%.0f",sum/i,sum,i);
    return 0;
}
