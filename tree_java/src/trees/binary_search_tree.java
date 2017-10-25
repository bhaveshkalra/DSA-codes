package trees;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class binary_search_tree {
	class tnode
    {
        int value;
        tnode left;
        tnode right;
        public tnode(int value)
        {
            this.value=value;
            left=null;
            right=null;
        }
        
    }
    tnode root;
    
    public  binary_search_tree(int number)
    {
         root=new tnode(number);
    }
     public void insert(int digit)
     {
         tnode temp=root;
         tnode parent=temp;
         tnode insert=new tnode(digit);
         while(temp!=null)
         {
             if(digit>=temp.value)
             {
                 parent=temp;
                 temp=temp.right;
             }
             else if(digit<temp.value)
             {
                 parent=temp;
                 temp=temp.left;
             }
            
         }
         if(digit>parent.value)
         {
             parent.right=insert;
         }
         else
         {
             parent.left=insert;
         }
     }
     public tnode search(int num)
     {
     tnode temp=root;
     int jhanda=0;
     while(temp!=null)
     {
         if(num>temp.value)
         {
             temp=temp.right;
         }
         else if(num<temp.value)
         {
             temp=temp.left;
         }
         else if(num==temp.value)
         {
              jhanda=1;
         }
         
     }
     if(jhanda==1){
     return temp;}
    else
     {
         System.out.print("node not found");
     }
     return null;
     }
     public void replace(int a , int b)
     {
         tnode to_replace=search(a);
         if(to_replace==null)
         {
             System.out.println("object not found");
         }
         else
         {
             to_replace.value=b;
         }
     }
     public tnode findMin(tnode temp_root)
     {
         tnode temp=temp_root;
         while(temp.left!=null)
         {
             temp=temp.left;
         }
         return temp;
     }
     
    // function to delete the given value
     public void delete_value(int a)
     {
         
     tnode temp=root;
     tnode parent=temp;
     int jhanda=0;
     while(temp!=null)
     {
         if(a>temp.value)
         {
             parent=temp;
             temp=temp.right;
         }
         else if(a<temp.value)
         {
             parent=temp;
             temp=temp.left;
         }
         else if(a==temp.value)
         {
              jhanda=1;
              break;
         }
         
     }
     if(jhanda==0)
     {
         System.out.println("element to delete not found");
         
     }
     else
     {
         if(temp.left==null&&temp.right==null)
         {
             //simply delete the node
            
         }
        if((temp.left==null&&temp.right!=null))
         {
             if(temp.value>parent.value)
             {
                   parent.right=temp.right;
                  
             }
             else
             {
                 parent.left=temp.right;
                
             }
         }
         if((temp.right==null&&temp.left!=null))
         {
              if(temp.value>parent.value)
             {
                   parent.right=temp.left;
                 
             }
             else
             {
                 parent.left=temp.left;
                 
             }
         
         }
         if(temp.left!=null&&temp.right!=null)
         {
             tnode replacement=findMin(temp.right);
             temp.value=replacement.value;
             replacement=null;
             //System.gc();
                     
         }
     }
     
     }
     public void preorder_traversal(tnode node)
     {
         if(node==null)
             return;
         preorder_traversal(node.left);
                  preorder_traversal(node.right);
                  System.out.print(node.value+" ");

     }
     public void inorder_traversal(tnode node)
     {
         if(node==null)
             return;
         inorder_traversal(node.left);
         System.out.print(node.value+" ");
         inorder_traversal(node.right);
     }
     public void preorder()
     {
         preorder_traversal(root);
         
     }
     public void inorder()
     {
         inorder_traversal(root);
         
     }
   
     public int height()
     {
         tnode anode=root;
         return maxDepth(anode);
     }
 public int maxDepth(tnode node) 
{
   if (node==null) 
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node.left);
       int rDepth = maxDepth(node.right);
 
       /* use the larger one */
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
} 
     public void level_traversal_2() throws InterruptedException
     {
         Queue<tnode> q1=new LinkedList<tnode>();
         //Queue<Integer> q2=new LinkedList<Integer>();
        
         tnode temp=root;
         q1.add(temp);
         //q1.add(null);
         while(q1.isEmpty()==false)
         {
        	 tnode out=q1.remove();
        	/* if(out==null)
        	 {
        		 System.out.println( );
        		 q1.add(null);
        	 }
        	 else*/
        	 {
        		 System.out.print(out.value+" ");
        		 if(out.left!=null) 
        		 {
        		 q1.add(out.left);
        		 }
        		 if(out.right!=null) 
        		 {
        		 q1.add(out.right);
        		 }
        	}
         }
       }
     public void reverseLOT()
     {
    	 Queue<tnode> queue= new LinkedList<>();
    	 Stack<tnode> stack=new Stack<>();
    	 tnode temp1=root;
    	 queue.add(temp1);
    	 while(queue.isEmpty()==false)
    	 {
    		 tnode pop=queue.remove();
    		 if(pop.left!=null) 
    		 {
    			 queue.add(pop.left);
    		 }
    		 if(pop.right!=null)
    		 {
    			 queue.add(pop.right);
    		 }
    		 stack.add(pop);
    		 
    			 
    	 }
    	while(stack.isEmpty()==false)
    	{
    		tnode node=stack.pop();
    		System.out.println(node.value+" ");
    		
    	}
     }
}
