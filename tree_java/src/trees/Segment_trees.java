package trees;



public class Segment_trees {
	int[] seg;
	public Segment_trees(int in[])
	{
		int seg_len = 0;
		int len=in.length;
		if(len==0)
		{
			
		}
		else
		{
			 seg_len=power2.calculate_next_power(len);
		}
		seg=new int[seg_len];
	
	}
	public void construct_seg_tree(int input[],int start,int end,int pos)
	{
		if(start==end)
		{
			seg[pos]=input[start];
		}
		else
		{
			int mid=(start+end)/2;
			construct_seg_tree(input, start, mid, 2*pos+1);
			construct_seg_tree(input, mid+1, end, 2*pos+2);
			seg[]
			
		}
		
	}
	
}
