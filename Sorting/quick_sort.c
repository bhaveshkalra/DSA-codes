/**
* Recursive implementation of quick sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static inline int quick_partition(int *arr, int start, int end)
{
    int x = arr[end];
    int i = start - 1;

    for(int j = start; j < end; j++)
    {
        if(arr[j] <= x)
        {
            i += 1;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }

    int t = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = t;

    return i + 1;
}

static inline void quick_sort_internal(int *arr, int start, int end)
{
    if(start < end)
    {
        int q = quick_partition(arr, start, end);
        quick_sort_internal(arr, start, q-1);
        quick_sort_internal(arr, q+1, end);
    }
}


/**
* Recursive quick sort
* @param arr array to reorder
* @param sz arr size
*/
void quick_sort(int *arr, int sz)
{
    if(!arr) return;

    quick_sort_internal(arr, 0, sz-1);
}


/**
* MAIN
*/
int main(int argc, char **argv)
{
    int arr[] = { 5, 34, 3412, 12, 3};

    quick_sort(arr, 5);

    printf("Ordered array:\n");
    for(int i=0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    } 

    return 0;
}