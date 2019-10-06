#include <iostream>
using namespace std;
int partition(int a[],int start, int end)
{
	int piv=a[start],i=start+1;
	for(int j=start+1;j<=end;j++)
	{
		if(a[j]<piv)
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
		}
	}
	int temp=a[i-1];
	a[i-1]=a[start];
	a[start]=temp;
	return i-1;
}
void quick_sort(int a[],int start,int end)
{
	if(start<end)
	{
		int piv_position=partition(a,start,end);
		quick_sort(a,start,piv_position-1);
		quick_sort(a,piv_position+1,end);
	}
}
int main()
{
	int a[100],n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		 cin>>a[i];
	}
	quick_sort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" "; 
	}
	return 0;
}