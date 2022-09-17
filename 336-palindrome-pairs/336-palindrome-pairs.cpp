class Solution {
bool check_palindrome(string &s)
    {
        int i=0;
        int j = s.length()-1;
        while(i<=j)
        {
            if(s[i++] != s[j--])
            {
                return false;
            }
        }
      return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
          vector<vector<int>> ans;
          unordered_map<string,int> mp;
          for(int i=0;i<words.size();i++)
          {
              string temp  = words[i];
              reverse(temp.begin(),temp.end());
              mp[temp] = i;
          }
        
          if(mp.find("") != mp.end())
          {
              for(int i=0;i<words.size();i++)
              {
                  if(!words[i].empty() && check_palindrome(words[i]))
                  {
                     ans.push_back({i,mp[""]});
                  }
              }
          }
        
          for(int i=0;i<words.size();i++)
          {
              string left="",right="";
              for(int j=0;j<words[i].size();j++)
              {
                  left.push_back(words[i][j]);
                  right = words[i].substr(j+1);
                 if(mp.count(left) && i != mp[left] && check_palindrome(right))
                 {
                     ans.push_back({i,mp[left]});
                 }
                  
                  if(mp.count(right) && i!=mp[right] && check_palindrome(left))
                  {
                      ans.push_back({mp[right],i});
                  }
                
              } 
          }
    return ans;
    }
};