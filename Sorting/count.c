#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n],i,j,max=0;
	
	for(i=0;i<n;i++){
	scanf("%d",&a[i]);
	if(a[i]>max)
		max=a[i];
	}

	int *c=(int *)malloc(sizeof(int)*(max+1));
	int b[n+1];
	for(i=0;i<=max;i++)
		c[i]=0;

	for(i=0;i<n;i++){
	c[a[i]]++;
	}
	for(i=1;i<=max;i++)
		c[i]+=c[i-1];
	for(i=n-1;i>=0;i--){
		b[c[a[i]]]=a[i];
		c[a[i]]--;
	}
	for(i=1;i<=n;i++)
		printf("%d ",b[i]);
	
	return 0;
}
