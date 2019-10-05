/**
* Iterative implementation of merge sort with arrays
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
* Sort array with iterative merge sort
* @param arr array pointer
* @param size arr size
* @returns 1 on error
*/
int merge_sort(int * arr, int size)
{
    if(!arr || size < 1) return 1;
    if(size == 1) return 0;

    int * swap_block = malloc(sizeof(int) * size);
    if(!swap_block) return 1; // can't allocate ram

    int *source = arr, *dest = swap_block;
    int h = 0, k = 0, items = 0, base = 0;

    int ch, ck; // index cache

    // iterate subarrays sizes
    for(int step = 2; step/2 < size; step *= 2)
    {
        for(int i = 0; i < size; i++)
        {
            // new subarray
            if(i % step == 0)
            {
                h = 0;
                k = 0;
                items = size - i;
                if(items > step) items = step;

                // this sub array is too short
                // and have just been ordered in a previous step
                // so we just copy it
                if(items < step/2) 
                {
                    memcpy(dest + i, source + i, items * sizeof(int));
                    break;
                }

                base = i; // start index of the subarray
            }

            // merge the two "virtual" subarrays to emulate recurion
            // base is the base array index
            // h is the index of the fist unmerged element of subarray 1
            // k is the index of the fist unmerged element of subarray 2
            // ch, ck are cached index to reduce math operations
            ch = base + h;
            ck = base + step/2 + k;
            if(h < step/2 && ( step/2 + k >= items || source[ch] < source[ck]) )
            {
                dest[i] = source[ch];
                h++;
            }
            else
            {
                dest[i] = source[ck];
                k++;

            }           
        }

        // swap the array to use as destination of merge 
        if(source == arr)
        {
            source = swap_block;
            dest = arr;
        }
        else
        {
            source = arr;
            dest = swap_block;
        }      
    }

    // We need to make sure that the data is written to the right array
    // the one passed as function paramter
    // this check seem wrong because the last for iteration swaps the arrays
    // so we need to use the opposite condition to check if the data is on the right array
    if(dest == arr)
    {
        memcpy(arr, swap_block, size * sizeof(int));
    }
    
    free(swap_block);
    return 0;
}


/**
* MAIN
*/
int main(int argc, char **argv)
{
    int arr[] = { 5, 34, 3412, 12, 3};

    merge_sort(arr, 5);

    printf("Ordered array:\n");
    for(int i=0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    } 

    return 0;
}