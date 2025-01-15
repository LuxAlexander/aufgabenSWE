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
    int** matrix[3]; // Array to hold matrix1, matrix2, and ergmatrix

    printf("Matrix Multiplication:\n");
    for (int i = 0; i < 2; i++) {
        printf("Dimensions of matrix %d:\n", i + 1); // Using i+1 for user-friendly indexing
        printf("Rows Columns\n");
        scanf("%d %d", &r[i], &c[i]);

        // Initialize and fill the matrix
        matrix[i] = initiliaze(r[i], c[i]);
        fill(matrix[i], r[i], c[i]);
    }

    // Print matrices
    print(matrix[0], r[0], c[0]);
    print(matrix[1], r[1], c[1]);

    // Initialize the result matrix
    matrix[2] = initiliaze(r[0], c[1]);

    // Perform matrix multiplication
    multiply(matrix[0], matrix[1], matrix[2], r, c);

    // Print the result matrix print(matrix[2], r[0], c[1]);

    // Free the dynamically allocated memory

    for (int i = 0; i < 3; i++) {
        int rows = (i == 2) ? r[0] : r[i];//fast for if(i==2) rows=r[0]else r[i]

        for (int j = 0; j < rows; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }


    return 0;
}


void multiply(int**matrix1,int**matrix2,int**ergmatrix,int*r,int*c) {
    if(check(c[0],r[1])==1) {
        for (int i = 0; i < r[0]; i++) { // Iterate over rows of matrix1
            for (int j = 0; j < c[1]; j++) { // Iterate over columns of matrix2
                ergmatrix[i][j]=0;
                printf("\n0");
                for (int k = 0,l=0; l < c[0] && k< r[1]; k++,l++) { // Multiply row of matrix1 with column of matrix2
                    printf(" + %d * %d ",(*(*(matrix1+i)+k)),(*(*(matrix2+k)+j)));// shows the elements which are to be multiplied.
                    ergmatrix[i][j] += (*(*(matrix1+i)+k)) * (*(*(matrix2+k)+j));
                }
                printf("\n");
            }
        }
        print(ergmatrix,r[0],c[1]);
    }
}
int check(int c1, int r1) {
    printf("Matrix 1 Columns need to match Matrix 2 Rows\n");//Check if the dimensions match.
    if(c1==r1) {
        printf("Possible\n");
        return 1;
    }else printf("Wrong Dimensions\n");
    return -1;
}
void fill(int** arr, int r, int c) {
    int temp= 0;
    //Fill the array with user inputs
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++) {
            printf("Enter element at (%d,%d):\n", i, j);
            scanf("%d", &temp);
            *(*(arr+i)+j) = temp; // array[i][j] OR *(*(arr+i)+j) = temp
        }
    }
}
void print(int** arr, int r, int c) {
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++) {
            printf("%d \t", *(*(arr+i)+j)); // array[i][j] = *(*(arr+i)+j)
        }
        printf("\n");
    }
}
int** initiliaze(int rows,int columns) {
    // Allocate memory for array of pointers
    int **matrix = (int**)malloc(rows * sizeof(int*));
    //first, save space for the rows and then for the rows.
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(columns * sizeof(int));
    }

    //Check if space has been reserved
    if (matrix == NULL) {
        // Allocation failed
        return -1;
    }

    return matrix;
}