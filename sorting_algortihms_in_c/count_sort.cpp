#include<iostream>
using namespace std;
void count_sort(int a[],int n)
{
	int max=a[0],arr[n];
	for(int i=1;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	int count[max+1]{0};
	/*int count[max+1];
	for(int i=0;i<=max;i++)
	{
		count[i]=0;
	}
	*/for(int i=0;i<n;i++)
	{
		count[a[i]]++;
	}
	for(int i=1;i<=max;i++)
	{
		count[i]=count[i-1]+count[i];
	}
	for(int i=n-1;i>=0;i--)
	{
		arr[--count[a[i]]]=a[i];
	}
	for(int i=0;i<n;i++)
	{
		a[i]=arr[i];
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
	count_sort(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" "; 
	}
	return 0;
}