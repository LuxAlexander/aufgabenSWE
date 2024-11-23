#include <stdio.h>
/*Schreiben Sie ein C-Programm basicCalculator,
 *das einen Grundrechenoperator und zwei Zahlen entgegennimmt,
 *die Rechnung durchführt und das Ergebnis ausgibt*/
int main(void) {
    float zahlen[3];
    char operation='.';

    while (operation!='e') {
        printf("Basic Calc!\n");
        printf("Geben Sie die gewuenschten Zahlen und operation in der Form X # Y ein!\n");
        scanf("%f %c %f",&zahlen[0],&operation,&zahlen[1]);


        switch (operation) {
            case '+':
                zahlen[3]=zahlen[0]+zahlen[1];
            break;
            case '-':
                zahlen[3]=zahlen[0]-zahlen[1];
            break;
            case '*':
                zahlen[3]=zahlen[0]*zahlen[1];
            break;
            case '/':
                zahlen[3]=zahlen[0]/zahlen[1];
            break;
            default:
                printf("No such operation defined. There are +,-,*,/ and e for exit");
        }
        if(operation>='*'&&operation<='/') {
            printf("%.2f %c %.2f = %.2f\n",zahlen[0],operation,zahlen[1],zahlen[3]);
        }
    }
    return 0;
}
