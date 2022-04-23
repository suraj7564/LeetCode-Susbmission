class Solution {
public:
    map <string,string> routeMap;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        const int size = longUrl.length();
        int itr =0,found = 0;
        while(itr<size){
            if(longUrl[itr] == '/')
                found = itr;
            ++itr;
        }
        if(found == 0)
            return longUrl;
        const string route = longUrl.substr(found+1,size);
        map<char,int> amap;
        for(const char ch: route)
            ++amap[ch];
        string out;
        for(auto itr = amap.begin();itr!=amap.end();++itr)
            out += itr->first+to_string(itr->second);
        
        itr=0;
        string temp;
        while(itr<=found){
            temp += longUrl[itr];
            ++itr;
        }
        out = temp + out;
        routeMap[out] = longUrl;
        return out;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        const int size = shortUrl.length();
        int itr =0,found = 0;
        while(itr<size){
            if(shortUrl[itr] == '/')
                found = itr;
            ++itr;
        }
        if(found == 0)
            return shortUrl;
        return routeMap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));