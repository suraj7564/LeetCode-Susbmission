//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String A = read.readLine();
            String B = read.readLine();

            Solution ob = new Solution();
            out.println(ob.minRepeats(A,B));
        }
        out.close();
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    static int minRepeats(String A, String B) {
        // code here
        int c=1;
        String str=A;
        while(A.length()<B.length()){
            A+=str;
            c++;
        }
        if(A.contains(B))return c;
        if((A+str).contains(B)) return c+1;
        else return -1;
    }
};