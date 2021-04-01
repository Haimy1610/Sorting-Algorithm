//Merge sort implementation by C language
#include <stdio.h>
#include <stdlib.h>
#define MAX 5000
  
// Merges two subarrays of arr[]
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1; //Size of first array
    int n2 = r - m; //Size of second array
  
    //Create temp arrays
    int L[n1], R[n2];
  
    //Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  
// l is for left index and r is right index of the sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
  
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}
  
//Function to print an array
void display(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
  

int main()
{
    int array[MAX],n,i;
    printf(" \nHow many numbers in the list? ");
    scanf ("%d", &n);
    for (i=0;i<n;i++)
    {
        printf ("\nAdd number %d: ",i+1);
        scanf ("%d",&array[i]);
        }
    printf (" \nNow the list you wanna sort is: ");
    display(array,n);
    printf ("\n");
  
    mergeSort(array,0, n - 1);
  
    printf("\nSorted array is \n");
    display(array, n);
    return 0;
}
