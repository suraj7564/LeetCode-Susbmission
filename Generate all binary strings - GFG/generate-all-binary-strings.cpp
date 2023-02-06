//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void print(string cur, int pre, int l){
        if(l == 0){
            cout<<cur<<" ";
            return;
        }
        print(cur + "0", 0, l - 1);
        if(pre != 1){
            print(cur + "1", 1, l - 1);
        }
    }
    void generateBinaryStrings(int& num){
        //Write your code
        print("", -1, num);
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        // cout << setprecision(9) << obj.switchCase(choice,vec) << endl;
        obj.generateBinaryStrings(n);
        cout << endl;
        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends