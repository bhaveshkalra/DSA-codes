#include<stdio.h> 
  
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
  
/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]);
    printf("n"); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int i,n;
    printf("Enter the no.of elements in the array\n");
    scanf("%d",&n);
    int A[n];

    printf("\n Input the elements of the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    printf("Array Input :\n");
    for(i=0;i<n;i++)
    {   
        printf("%d\n",A[i]);
    }

    // Calling quick sort to sort the array.
    quickSort(A,0,n);

    //printing all elements in the array once its sorted.
    printf("Array Elements after sorting are:\n");
    for(i = 0;i <n;i++) printf("%d element is:\t%d\n",i+1,A[i]);
    return 0;
} 