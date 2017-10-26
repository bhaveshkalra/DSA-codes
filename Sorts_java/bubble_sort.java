
public class bubble_sort {
	public static void b_sort(int arr[])
	{
		int len=arr.length;
		for(int i=0;i<len;i++)
		{
			for(int j=0;j<len-1;j++)
			{
				if(arr[j]>arr[j+1])
				{
					int temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
		}
	}
}
}
