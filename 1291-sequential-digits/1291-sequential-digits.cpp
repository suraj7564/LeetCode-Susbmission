class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
        vector<int> v;
        int nl=to_string(low).length();
        int nh=to_string(high).length();
        
        for(int i=nl;i<=nh;i++){
            for(int j=0;j<10-i;++j){
                int num=stoi(s.substr(j,i));
                if(num>=low && num<=high) v.push_back(num);
            }
        }
        return v;
    }
};