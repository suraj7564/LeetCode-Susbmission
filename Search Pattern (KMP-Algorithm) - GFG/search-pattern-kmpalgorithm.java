//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0)
        {
            String s, patt;
            s = sc.next();
            patt = sc.next();
            
            Solution ob = new Solution();
            
            ArrayList<Integer> res = ob.search(patt, s);
            if(res.size()==0)
                System.out.print(-1);
            else {
                for(int i = 0;i<res.size();i++)
                    System.out.print(res.get(i) + " ");
            }
            System.out.println();    
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    
    public static void lpsfind(int[] lps, String s){

        int pre=0,suf=1;

        while(suf<s.length()){
            if(s.charAt(pre)==s.charAt(suf)){
                lps[suf]=pre+1;
                pre++;
                suf++;
            }
            else{
                if(pre==0){
                    lps[suf]=0;
                    suf++;
                }
                else{
                    pre = lps[pre-1];
                }
            }
        }

    }

    ArrayList<Integer> search(String pat, String txt)
    {
        // your code here
        ArrayList<Integer> al = new ArrayList<>();
        int[] lps = new int[pat.length()];
        lpsfind(lps,pat);
        int first=0, second=0;
        while(first<txt.length()){
            //matched
            if(txt.charAt(first)==pat.charAt(second)){
                first++;
                second++;
            }
            else{
                if(second==0){
                    first++;
                }
                else{
                    second=lps[second-1];
                }
            }
            if(second==pat.length()){
                al.add(first-second+1);
              second=lps[second-1];
            }
        }//end of while
       return al;

    }
}