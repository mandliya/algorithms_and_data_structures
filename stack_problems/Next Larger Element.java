

import java.util.*;
import java.lang.*;
import java.io.*;

class gfg_next_larger {
	public static void main (String[] args) {
		//code
		
		int i,j,n;
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		while(t --> 0)
		 {
		      int k=0;
		      n = s.nextInt();
		      long arr[] = new long[n];
		      
		      for(i=0 ; i<arr.length ; i++)
		          arr[i] = s.nextLong();
		          
		      Stack<Long> stack = new Stack<Long>();
		      long res[] = new long[n];
		      
		      for(i=arr.length-1 ; i>=0 ; i--)
		       {
		             if(i == arr.length -1 )
		                 {
		                     res[k++] = -1;
		                     stack.push(arr[i]);
		                 }
		             else
		              {
		                   while(!stack.isEmpty() && stack.peek() <= arr[i])
		                    {
		                         stack.pop();
		                    }
		                    if(!stack.isEmpty())
		                     { 
		                         res[k++] = stack.peek();
		                         stack.push(arr[i]);
		                     }
		                     else
		                     {
		                         stack.push(arr[i]);
		                          res[k++] = -1;
		                     }
		              }
		                 
		       }
		       for(i=res.length-1 ; i>=0 ; i--)
		           System.out.print(res[i] + " ");
		           
		      System.out.println();
		 }
		
	}
}