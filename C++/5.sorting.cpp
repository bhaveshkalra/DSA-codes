//============================================================================
// Name        : sorting.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Mysort{
	int num_students,i,j;
	float a[50];

public:
	void accept();
	void display();
	void sort_bubble();
	void sort_insertion();
	void sort_merge(float[10],int,int);
	void merge1(float[10],int,int,int);
	void des_merge2(float[10],int,int,int);
	void mergesort_des(float[10],int,int);
	void callMerge();
};
void Mysort::accept()
{
	cout<<"Enter the total no. of first year students "<<endl;
	cin>>num_students;
	cout<<"Enter CGPA of students"<<endl;
	for(i=0;i<num_students;i++)
	{
		cin>>a[i];
	}


}
void Mysort::display()
{
	cout<<"\nThe CGPA of first year students is"<<endl;
	for(i=0;i<num_students;i++)
	{
		cout<<a[i]<<",  ";
	}
	cout<<"\n\n";
}
void Mysort::sort_bubble()
{
	int flag=0;
	float temp=0;
	cout<<"Ascending order"<<endl;
	for(i=0;i<num_students;i++)
	{
		for(j=0;j<num_students-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag++;

			}

		}


		  cout<<"pass "<<i+1<<":- ";
		  for(j=0;j<num_students;j++)
		  cout<<a[j]<<"\t";
		  cout<<endl;
	}
	     if(flag==0)
		cout<<"\nBEST CASE"<<endl;
		  else if(flag==num_students-1)
			  cout<<"\nWORST CASE"<<endl;

	     cout<<"\nDescending order"<<endl;
	     		  for(i=0;i<num_students;i++)
	     		  	{
	     		  		for(j=0;j<num_students-1;j++)
	     		  		{
	     		  			if(a[j]<a[j+1])
	     		  			{
	     		  				temp=a[j];
	     		  				a[j]=a[j+1];
	     		  				a[j+1]=temp;

	     		  			}

	     		  		}


	     		  		  cout<<"pass "<<i+1<<":- ";
	     		  		  for(j=0;j<num_students;j++)
	     		  		  cout<<a[j]<<"\t";
	     		  		  cout<<endl;
	     	      }

}
void Mysort::sort_insertion()
{
	cout<<"\n";
	cout<<"Ascending order"<<endl;
	float temp;
	for(i=0;i<num_students;i++)
	{
		temp=a[i];
		j=i-1;
		while(j>=0&&a[j]>temp)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
		cout<<"pass "<<i+1<<":- ";
		for(j=0;j<num_students;j++)
		cout<<a[j]<<"\t";
		cout<<endl;
	}
	cout<<"\nDescending order"<<endl;
			for(i=0;i<num_students;i++)
			{
					temp=a[i];
					j=i-1;
					while(j>=0&&a[j]<temp)
					{
						a[j+1]=a[j];
						j--;
					}
					a[j+1]=temp;
					cout<<"pass "<<i+1<<":- ";
					for(j=0;j<num_students;j++)
					cout<<a[j]<<"\t";
					cout<<endl;
		  }

}
void Mysort::merge1(float a[20],int low,int mid,int high)//for ascending
{
	int k=0;
	float c[10];
	i=low;
	j=mid+1;
	while(i<=mid&&j<=high)
    {
        if(a[i]<a[j])
        {
            c[k]=a[i];
            k++;
            i++;
        }
        else
            {
                c[k]=a[j];
                k++;
                j++;
            }
    }
	while(i<=mid)       //to print the remaining elements in
	{
        c[k]=a[i];
        k++;
        i++;
	}
    while(j<=high)
    {
        c[k]=a[j];
        k++;
        j++;
    }
    for(i=low;i<=high;i++)
    {
        a[i]=c[i-low];
    }

}


void Mysort::sort_merge(float a[20],int low,int high)//ascending
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		sort_merge(a,low,mid);
		sort_merge(a,mid+1,high);
		merge1(a,low,mid,high);
	}

}

void Mysort::des_merge2(float a[20],int low,int mid,int high)//for descending
{
	int k=0;
		float c[10];
		i=low;
		j=mid+1;
		while(i<=mid&&j<=high)
	    {
	        if(a[i]>a[j])
	        {
	            c[k]=a[i];
	            k++;
	            i++;
	        }
	        else
	            {
	                c[k]=a[j];
	                k++;
	                j++;
	            }
	    }
		while(i<=mid)       //to print the remaining elements in
		{
	        c[k]=a[i];
	        k++;
	        i++;
		}
	    while(j<=high)
	    {
	        c[k]=a[j];
	        k++;
	        j++;
	    }
	    for(i=low;i<=high;i++)
	    {
	        a[i]=c[i-low];
	    }
}

void Mysort::mergesort_des(float a[20],int low,int high)//descending
{	int mid;
		if(low<high)
		{
			mid=(low+high)/2;
			sort_merge(a,low,mid);
			sort_merge(a,mid+1,high);
			des_merge2(a,low,mid,high);
		}
}
void Mysort::callMerge()    //calling merge sort function
{
    sort_merge(a,0,num_students-1);
    cout<<"The merge sorted list is"<<endl;
    for(i=0;i<num_students;i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    mergesort_des(a,0,num_students-1);
   cout<<"Descending order"<<endl;
    for(i=0;i<num_students;i++)
    {
        cout<<a[i]<<"\t";
    }

}
int main()
{
	Mysort s;
	int option;
	char ans;
	do{
		cout<<"Enter your choice\n1.bubble sort\n2.insertion sort\n3.Merge sort\n";
		cin>>option;
		switch(option)
		{
		case 1:
			s.accept();
			s.display();
			s.sort_bubble();
			break;
		case 2:
			s.accept();
			s.display();
			s.sort_insertion();
			break;
		case 3:
			s.accept();
			s.display();
			s.callMerge();
		    break;
		default:
			cout<<"Invalid option"<<endl;

		}
		cout<<"\nWould you like to continue?Y or N"<<endl;
		cin>>ans;
	}while(ans=='Y'||'y');

	return 0;
}

//OUTPUT
/*
 * Enter your choice
1.bubble sort
2.insertion sort
3.Merge sort
1
Enter the total no. of first year students
5
Enter CGPA of students
3.4 4.7 5.6 6.7 7.8

The CGPA of first year students is
3.4,  4.7,  5.6,  6.7,  7.8,

Ascending order
pass 1:- 3.4	4.7	5.6	6.7	7.8
pass 2:- 3.4	4.7	5.6	6.7	7.8
pass 3:- 3.4	4.7	5.6	6.7	7.8
pass 4:- 3.4	4.7	5.6	6.7	7.8
pass 5:- 3.4	4.7	5.6	6.7	7.8

BEST CASE

Descending order
pass 1:- 4.7	5.6	6.7	7.8	3.4
pass 2:- 5.6	6.7	7.8	4.7	3.4
pass 3:- 6.7	7.8	5.6	4.7	3.4
pass 4:- 7.8	6.7	5.6	4.7	3.4
pass 5:- 7.8	6.7	5.6	4.7	3.4

Would you like to continue?Y or N
y
Enter your choice
1.bubble sort
2.insertion sort
3.Merge sort
2
Enter the total no. of first year students
6
Enter CGPA of students
6.7 7.7 8.7 5.9 9.0 6.9

The CGPA of first year students is
6.7,  7.7,  8.7,  5.9,  9,  6.9,


Ascending order
pass 1:- 6.7	7.7	8.7	5.9	9	6.9
pass 2:- 6.7	7.7	8.7	5.9	9	6.9
pass 3:- 6.7	7.7	8.7	5.9	9	6.9
pass 4:- 5.9	6.7	7.7	8.7	9	6.9
pass 5:- 5.9	6.7	7.7	8.7	9	6.9
pass 6:- 5.9	6.7	6.9	7.7	8.7	9

Descending order
pass 1:- 5.9	6.7	6.9	7.7	8.7	9
pass 2:- 6.7	5.9	6.9	7.7	8.7	9
pass 3:- 6.9	6.7	5.9	7.7	8.7	9
pass 4:- 7.7	6.9	6.7	5.9	8.7	9
pass 5:- 8.7	7.7	6.9	6.7	5.9	9
pass 6:- 9	8.7	7.7	6.9	6.7	5.9

Would you like to continue?Y or N
y
Enter your choice
1.bubble sort
2.insertion sort
3.Merge sort
3
Enter the total no. of first year students
8
Enter CGPA of students
7.7 6.7 8.7 9.8 9.1 7.8 5.6 6.6

The CGPA of first year students is
7.7,  6.7,  8.7,  9.8,  9.1,  7.8,  5.6,  6.6,

The merge sorted list is
5.6	6.6	6.7	7.7	7.8	8.7	9.1	9.8
Descending order
7.8	8.7	9.1	9.8	5.6	6.6	6.7	7.7
Would you like to continue?Y or N
 */

