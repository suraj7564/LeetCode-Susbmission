class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> m;
        for(auto x:words){
            m[x]++;
        }
        int x1=0,ans=0;
        for(auto x:m){
            string s=x.first;
            string s1=s;
            swap(s1[0],s1[1]);
            if(s!=s1){
                ans+=2*min(m[s],m[s1]);
            }
            else{
                ans+=4*(m[s]/2);
                if(m[s]%2) x1=2;
            }
        }
        ans+=x1;
        return ans;
    }
};