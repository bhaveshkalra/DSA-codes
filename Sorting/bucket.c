#include<stdio.h>
#include<time.h>

int arr[10001][101];

void read(int a[],int n){
	FILE *fptr;
	fptr=fopen("best.txt","r");
	if(fptr==NULL)
	{
	printf("file cannot be open");
	return ;
	}
	int i;
	for(i=n-1;i>=0;i--){
	fscanf(fptr,"%d",&a[i]);
	}
//return;	
}

void insertion_sort(int a[],int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		for(j=i;j>0;j--){
		if(a[j]>a[j-1])
		break;
		else{
			temp=a[j];
			a[j]=a[j-1];
			a[j-1]=temp;			
			}		
		}
	}
	//for(i=0;i<n;i++)
	//printf("%d ",a[i]);
}

void bucket(int a[],int n){
	
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<100&&arr[a[i]/10][j]!=0;j++);
		arr[a[i]/10][j]=a[i];
	}
	
	for(i=0;i<10000;i++){
		for(j=0;j<100&&arr[i][j]!=0;j++);
		insertion_sort(arr[i],j);
	}
	for(i=0;i<10000;i++){
		for(j=0;j<100&&arr[i][j]!=0;j++)
		{
		//printf("%d ",arr[i][j]);
		}
	}
		
}

int main(){
	int n;
	scanf("%d",&n);
	n=n*1000;
	int a[n],i,j;
	read(a,n);
	
	clock_t start,end;
	start=clock();
	bucket(a,n);
	end=clock();
	double time=((double)end-(double)start)/CLOCKS_PER_SEC;
	printf("time taken: %lf\n",time);
return 0;
}
