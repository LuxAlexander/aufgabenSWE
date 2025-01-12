#include <stdio.h>
#include <stdlib.h>//memory allocation

/* ============================================================================
 * Name : matrixMultiplication.c
 * Author : Alexander Lux
 * Version : 1.0
 * Description : Matrix Multiplication from variable sizes
 * ============================================================================ */

int** initiliaze(int,int);

void print(int**,int,int);
void fill(int**,int,int);
int check(int,int);
void multiply(int**,int**,int**,int*,int*);
int main(void)
{
    int r[2], c[2];
    int** matrix1;
    int** matrix2;
    int** ergmatrix;

    printf("Matrix Multiplication:\n");
    for(int i=0;i<2;i++) {

        printf("Dimensions of matrix %d:\n",i);
        printf("Rows Coloumns\n");
        scanf("%d %d",&r[i],&c[i]);

        if(i==0) {//Could be refactored and made into an array matrix[2]
            matrix1=initiliaze(r[i],c[i]);
            fill(matrix1,r[i],c[i]);
        }else {
            matrix2=initiliaze(r[i],c[i]);
            fill(matrix2,r[i],c[i]);

        }
    }

    print(matrix1,r[0],c[0]);
    print(matrix2,r[1],c[1]);
    ergmatrix=initiliaze(r[1],c[0]);

    multiply(matrix1,matrix2,ergmatrix,r,c);

    /*free the dynamically allocated memory first every element in row and then the whole.*/
    for (int i = 0; i < r[0]; i++) {
        free(matrix1[i]);
    }


    for (int i = 0; i < r[1]; i++) {
        free(matrix2[i]);
        free(ergmatrix[i]);
    }

    free(matrix1);
    free(matrix2);
    free(ergmatrix);

    return 0;
}
void multiply(int**matrix1,int**matrix2,int**ergmatrix,int*r,int*c) {
    if(check(c[0],r[1])==1) {
        for (int i = 0; i < r[0]; i++) { // Iterate over rows of matrix1
            for (int j = 0; j < c[1]; j++) { // Iterate over columns of matrix2
                ergmatrix[i][j]=0;
                printf("\n0");
                for (int k = 0,l=0; l < c[0] && k< r[1]; k++,l++) { // Multiply row of matrix1 with column of matrix2
                    printf(" + %d * %d \t",(*(*(matrix1+i)+k)),(*(*(matrix2+k)+j)));
                    ergmatrix[i][j] += (*(*(matrix1+i)+k)) * (*(*(matrix2+k)+j));
                }
                printf("\n");
            }
        }
        print(ergmatrix,r[0],c[1]);
    }
}
int check(int c1, int r1) {
    printf("Matrix 1 Columns need to match Matrix 2 Rows\n");
    if(c1==r1) {
        printf("Possible\n");
        return 1;
    }else printf("Wrong Dimensions\n");
    return -1;
}
void fill(int** arr, int r, int c) {
    int temp= 0;

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++) {
            printf("Enter element at (%d,%d):\n", i, j);
            scanf("%d", &temp);
            *(*(arr+i)+j) = temp; // OR *(*(arr+i)+j) = ++count
        }
    }
}
void print(int** arr, int r, int c) {
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++) {
            printf("%d \t", *(*(arr+i)+j)); // *(*(arr+i)+j)
        }
        printf("\n");
    }
}
int** initiliaze(int rows,int columns) {
    // Allocate memory for 10 integers
    int **matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(columns * sizeof(int));
    }


    if (matrix == NULL) {
        // Allocation failed
        return -1;
    }
    return matrix;
}