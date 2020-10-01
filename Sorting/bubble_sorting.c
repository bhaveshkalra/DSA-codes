#include<stdio.h>
void bubble_sort(int, int*);
void main()
{	int n, list[20], i;
	printf("input the number of elements of the list\n ");
	scanf("%d",&n);
	printf("\n Input the elements of the list\n");
	for(i=0;i<n;i++){
		scanf("%d",&list[i]);
	}
	printf("List Input :\n");
	for(i=0;i<n;i++)	
	{	printf("%d\n",list[i]);
	}
	applyBubbleSort(n,list);
}
void applyBubbleSort(int n, int arr[])
{	int temp,i,j;
	for(i=0;i<n;i++)
	{	for(j=0;j<n-i-1;j++)
		{
		if(arr[j]>arr[j+1])
			{	
			temp = arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
			}
		}
	}
 	printArray(n, arr);
} 

void printArray(int size, int arr[]) {
	printf("\n Sorted list\n");
	for(i=0;i<size;i++)
	{	printf("%d\n",arr[i]);
	}
}
