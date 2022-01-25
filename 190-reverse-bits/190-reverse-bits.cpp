class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t mask=1;
        string ans;
        unsigned long long res=0;
        
        for(int i=0;i<32;i++){
            
            if((mask&n)!=0)
                ans+="1";
            else
                ans+="0";
            
            mask <<= 1;
        }   
        
        return stoll(ans,0,2);
    }
};