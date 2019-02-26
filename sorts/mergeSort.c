#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[n1];
    int right[n2];
    int i, j, idx;
    for (i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (j = 0; j < n2; j++)
        right[j] = arr[j + m + 1];
    i = 0, j = 0, idx = l;
    while ( i < n1 && j < n2)
    {
        if (left[i] < right[j])
            arr[idx++] = left[i++];
        else
            arr[idx++] = right[j++];
    }

    while ( i < n1)
        arr[idx++] = left[i++];
    while (j < n2)
        arr[idx++] = right[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

int main(int argc, char* argv[])
{
    
    int arr[argc - 1];
    int size = argc - 1;
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = atoi(argv[i+1]);
    }
    printf("Size of array %d\n", size);

    mergeSort(arr, 0, size - 1);

    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

}