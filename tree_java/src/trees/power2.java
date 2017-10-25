package trees;

public class power2 {
	public static int calculate_next_power(int num)
	{
		
		for(int i=0;i<num;i++)
		{
			if(Math.pow(2, i)>=num)
			{
				return (int) Math.pow(2, i);
			}
		}
		return 0;
		
	}
}
