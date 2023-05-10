//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        
        
        int i = 0, j = 0, n = mat.size(); 
  
    
        bool isUp = true; 
        vector<int> ans;
      
        // Traverse the matrix till all elements get traversed 
        for (int k = 0; k < n * n;) { 
            // If isUp = true then traverse from downward 
            // to upward 
            if (isUp) { 
                for (; i >= 0 && j < n; j++, i--) { 
                    ans.push_back(mat[i][j]);
                    k++; 
                } 
      
                // Set i and j according to direction 
                if (i < 0 && j <= n - 1) 
                    i = 0; 
                if (j == n) 
                    i = i + 2, j--; 
            } 
      
            // If isUp = 0 then traverse up to down 
            else { 
                for (; j >= 0 && i < n; i++, j--) { 
                    ans.push_back(mat[i][j]);
                    k++; 
                } 
      
                // Set i and j according to direction 
                if (j < 0 && i <= n - 1) 
                    j = 0; 
                if (i == n) 
                    j = j + 2, i--; 
            } 
      
            // Revert the isUp to change the direction 
            isUp = !isUp; 
        } 
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends