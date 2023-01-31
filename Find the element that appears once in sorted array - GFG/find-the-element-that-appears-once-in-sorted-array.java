//{ Driver Code Starts
//Initial Template for Java

import java.util.*;

public class GFG 
{
    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        while (t-- > 0) 
        {
            int n = sc.nextInt();
            int arr[] = new int[n];
            for (int i = 0;i < n;i++)
            {
                arr[i] = sc.nextInt();
            }
            
            Solution sol = new Solution();
            System.out.println(sol.findOnce(arr, n));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution 
{
    int findOnce(int arr[], int n)
    {
        // Complete this function
        //1 1 2 2 3 3 4 50 50 65 65
        //l = 0, r = 10
        //step - 1 : m = 5, l = 6 r = 10
        //step - 2 : m = 8 l = 6, r = 7
        //step - 3 : m = 6, l = 6, r = 5
        int l = 0, r = n - 1;
        while(l <= r){
            int m = (l + r)/2;
            if(m%2 == 0){
                if(m + 1 < n && arr[m] == arr[m + 1]) l = m + 1;
                else r = m - 1;
            }
            else{
                if(m + 1 < n && arr[m] == arr[m + 1]) r = m - 1;
                else l = m + 1;
            }
        }
        return arr[l];
    }
}