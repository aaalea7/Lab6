// Part B: Quick Sort

// Write a C program for Quick Sort using divide-and-conquer method. Make sure you use recursion for the implementation of Quick Sort. 

// Output of part B should contain the input array taken from the user and the output (sorted) array.

// Example of output for part B:
// Input array : 2, 10, 56, 19, -4, 5, 7, 9
// Output array: -4, 2, 5, 7, 9, 10, 19, 56

#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int l, int h) {
    int pivot = arr[h];
    int i = (l - 1);

    for (int j=l; j<h; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[h]);
    return (i+1);
}

void quickSort(int arr[], int l, int h) {
    if (l<h) {
        int pivot_index = partition(arr, l, h);

        quickSort(arr, l, pivot_index - 1);
        quickSort(arr, pivot_index + 1, h);
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int arr[] = {2, 10, 56, 19, -4, 5, 7, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Input array: ");
    printArray(arr, n);
    
    quickSort(arr, 0, n-1);
    printf("Output array: ");
    printArray(arr, n);
}