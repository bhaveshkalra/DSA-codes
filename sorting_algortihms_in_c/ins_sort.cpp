#include <iostream>
using namespace std;
void sort(int a[],int n)
{
	int temp,j;
	for(int i=1;i<n;i++)
	{
		temp=a[i];
		j=i;
		while(j>0 && temp<a[j-1])
		{
			a[j]=a[j-1];
			j--;
		}
		a[j]=temp;
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
	sort(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}