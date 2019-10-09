/*FREQUENCY OF CHARACTERS*/
#include<stdio.h>
int main()
{
	int count[26]={0}, COUNT[26]={0};
	char str[100];
	printf("Enter the string: ");
	scanf("%s",str);
	for(int i=0;str[i]!='\0';++i)
	{
		if(str[i]>='a'|| str[i]<='z')
			count[str[i]-97]++;
		if(str[i]>='A'|| str[i]<='Z')
			COUNT[str[i]-65]++;

	}
	for(int i=0;i<26;i++){
		if(count[i]!=0)
		printf("%c occurs %d times\n",i+97,count[i]);
		if(COUNT[i]!=0)
		printf("%c occurs %d times\n",i+65,COUNT[i]);
	}
	return 0;
}
