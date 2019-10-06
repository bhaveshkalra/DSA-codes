#include<stdio.h>
#include<time.h>

void read(int a[],int n){
	FILE *fptr;
	fptr=fopen("worst.txt","r");
	if(fptr==NULL)
	{
		printf("file cannot be open");
		return ;
	}
	int i;
	//for(i=n-1;i>=0;i--)
	//	fscanf(fptr,"%d",&a[i]);
		for(i=0;i<n;i++)
		fscanf(fptr,"%d",&a[i]);	
	
	return;	
	
}

void quicksort(int *number,int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

int main(){
	int i,n;
    printf("Enter the no.of elements in the array\n");
    scanf("%d",&n);
    int arr[n];

    printf("\n Input the elements of the array\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
   n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    printf("Array Output :\n");
	for(i=0; i<n; i++)
    {
        printf("%d\n",arr[i]);
    }
	
	
	return 0;

	
}
