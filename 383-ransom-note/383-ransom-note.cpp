class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m=ransomNote.length();
        int n=magazine.length();
        if(m>n)
            return false;
        unordered_map<char,int> mp;

        for(int i=0; i<n; i++)
            mp[magazine[i]]++;

        for(int i=0; i<m; i++) {
            if(!mp.count(ransomNote[i]))
                return false;
            else 
                mp[ransomNote[i]]--;
            if(mp[ransomNote[i]]==0)
                mp.erase(ransomNote[i]);
        }
        return true;
    }
};