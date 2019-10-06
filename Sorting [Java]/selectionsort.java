import java.util.*;
class selectionsort
{
	public static void selectionsort(int []arr)
	{
		int min,temp;
		for (int i = 1; i<= arr.length - 1; i++) 
		{
			min=i;
			for (int j = i + 1; j < arr.length; j++) 
			{
				if (arr[j] < arr[min]) 
				{
					min = j;			
				}
				temp = arr[i];
				arr[i] = arr[min];
				arr[min] = temp;		
			}	
		}
	}

	public static void main(String[] args) 
	{
		int [] arr = {1,55,44,215,2,6,8};
		selectionsort(arr);
		for (int i = 0; i < arr.length; i++) 
		{
			System.out.println(arr[i]);	
		}
	}
}