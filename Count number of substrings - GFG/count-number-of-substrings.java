//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main (String[] args)
    {
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            String s = sc.next ();
            int k = sc.nextInt();
    		System.out.println (new Solution().substrCount (s, k));
        }
        
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    long substrCount (String s, int k) {
        // your code here
        return solve(s,k)-solve(s,k-1);
    }
    long solve(String s, int k) {
        int i=0,j=0,size=0,n=s.length();
        long ans=0;
        int[] map = new int[26];
        while(j<n) {
            char cha = s.charAt(j);
            if(map[cha-'a']==0) size++;
            map[cha-'a']++;
            while(size>k) {
                char chr = s.charAt(i);
                map[chr-'a']--;
                if(map[chr-'a']==0) size--;
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
}