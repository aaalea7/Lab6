// Part A: Merge Sort

// Write a C program for Merge Sort using divide-and-conquer method. Make sure you use recursion for the implementation of Merge Sort. 

// Output of part A should contain the input array taken from the user and the output (sorted) array.

// Example of output for part A:
// Input array : 2, 10, 56, 19, -4, 5, 7, 9
// Output array: -4, 2, 5, 7, 9, 10, 19, 56


#include <stdio.h>

// merges two subarrays
void merge(int arr[], int l, int m, int h) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = h - m;

    // create two temp arrays
    int L[n1], R[n2];

    // copy the data to the temp arrays
    for (i=0; i<n1; i++) {
        L[i] = arr[l + i];
    }
    for (j=0; j<n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // merge two temp arrs
    i = 0;
    j = 0;
    k = l;
    while (i<n1 && j<n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // add the remaining elements of L[]
    while (i<n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // add the remaining elements of R[]
    while (j<n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// recursion
void mergeSort(int arr[], int l, int h) {
    if (l<h) {
        int m = l + (h - l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, h);

        merge(arr, l, m, h);
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
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Size of the array is %d\n", arr_size);
    printf("Input array: ");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);
    printf("Output array: ");
    printArray(arr, arr_size);

    return 0;
}