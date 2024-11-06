#include <iostream>

void fillarray(int [],int);
void printarray(int [],int);

void insertionsort(int [],int);
void selectionsort(int [],int);

void mergesort(int [],int,int);
void merge(int [], int , int , int );

void quicksort(int [],int);
void heapsort(int [],int);
void bubblesort(int [],int);

int main() {
    int basearray[] = {44, 23, 1, 2, 5, 6, 12, 66, 3, 10};
    int tosort[] = {44, 23, 1, 2, 5, 6, 12, 66, 3, 10};
    int lenght = sizeof(tosort) / sizeof(int);

    printf("Base Array: ");
    printarray(basearray, lenght);

    printf("\n\nTo Sort: ");
    mergesort(tosort, lenght, 0);

    //insertionsort(tosort, lenght);
    //selectionsort(tosort, lenght);
    //bubblesort(tosort, lenght);
    printarray(tosort, lenght);
    return 0;
}

void printarray(int arr[], int len) {
    printf("\nArray : \n");
    for (int i = 0; i < len; i++) {
        printf(".%d. ",arr[i]);
    }
}

void bubblesort(int arr[], int len) {
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void selectionsort(int arr[], int len) {
    int temp=0,spot=0;
    int min;

    for(int i = 0; i < len; i++) {
        min=arr[i];
        spot=i;

        for(int j=len-1;j>i;j--) {
            if(arr[j]<min) {
                min = arr[j];
                spot=j;
            }
        }
        temp = arr[i];
        arr[i] = min;
        arr[spot] = temp;
    }
}
void insertionsort(int arr[], int len) {
    int pivot,temp;
    for(int i = 1; i < len; i++) {
        pivot = i;
        for(int j=pivot;j>0;j--) {
            if(arr[j] < arr[j-1]) {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

void mergesort(int arr[], int len, int start) {
    if (len > 1) {
        int mid = start + (len / 2);
        printf("\nDividing array at index %d\n", mid);

        mergesort(arr, mid - start, start);          // Left half
        mergesort(arr, len - (mid - start), mid);    // Right half

        merge(arr, start, mid - 1, start + len - 1);
    }
}

void merge(int arr[], int start, int mid, int end) {
    int left_len = mid - start + 1;
    int right_len = end - mid;
    int il = 0, ir = 0, ig = start;

    int left[left_len], right[right_len];

    for (int i = 0; i < left_len; i++) {
        left[i] = arr[start + i];
    }
    for (int j = 0; j < right_len; j++) {
        right[j] = arr[mid + 1 + j];
    }

    while (il < left_len && ir < right_len) {
        if (left[il] <= right[ir]) {
            arr[ig++] = left[il++];
        } else {
            arr[ig++] = right[ir++];
        }
    }
    
    while (il < left_len) {
        arr[ig++] = left[il++];
    }

    while (ir < right_len) {
        arr[ig++] = right[ir++];
    }
}
