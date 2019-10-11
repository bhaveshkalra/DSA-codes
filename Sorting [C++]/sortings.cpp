#include <bits/stdc++.h> 
using namespace std; 
  
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  /* Function to print an array */
void printArray(int arr[], int size)  
{  
    int i;  
    for (i=0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
// Selection Sort
void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]);  
    }  
} 
// Bubble sort  
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
} 
// Insertion Sort  
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
} 
// Quick Sort
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high];   
    int i = (low - 1);  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
//The main function that implements QuickSort  
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        int pi = partition(arr, low, high);  
  
        /* Separately sort elements before  
         partition and after partition*/  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  
        
// Driver program to test above functions  
int main()  
{  
	int n;
	cout<<"Enter the number of elements of the array\n";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of the array\n";
	for(int j=0;j<n;j++)
	cin>>arr[j]; 
    selectionSort(arr, n);  
    cout << "Selection Sorted Array: \n";  
    printArray(arr, n); 
    
	/*bubbleSort(arr, n);  
    cout<<"Bubble Sorted Array: \n";  
    printArray(arr, n);*/
	
	/*insertionSort(arr, n);  
    cout<<"Insertion Sorted Array: \n";  
    printArray(arr, n);*/  
	
	/*quickSort(arr, n);  
    cout<<"Quick Sorted Array: \n";  
    printArray(arr, n);*/  
    return 0;  
}  
