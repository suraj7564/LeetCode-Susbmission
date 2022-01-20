// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to find out the number of ways to use the coins to
    //sum up to a certain required value.
    long long numberOfWays(int coins[],int value,int n)
    {
        long long dp[n+1][value];
        for(int i=0;i<value;i++){
            dp[0][i]=1;   
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<value;j++){
                dp[i][j]=0;
                if((i-coins[j])>=0){
                    dp[i][j]+=dp[i-coins[j]][j];
                }
                if(j>0){
                    dp[i][j]+=dp[i][j-1];
                }
            }
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<value;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n][value-1];
    }
};


// { Driver Code Starts.


int main() {
    
    //taking total count of testcases
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    //taking value
	    int value;
	    cin>>value;
	    
	    //taking number of coins
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    //inserting coins to the array
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    Solution obj;
	    //calling function numberOfWays
	    cout<<obj.numberOfWays(coins,numberOfCoins,value)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends