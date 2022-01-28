class WordDictionary {
public:
    unordered_map<int,vector<string> > m;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        m[word.size()].push_back(word);
        
    }
    
    bool search(string word) {
        for(auto x:m[word.size()]){
            bool b=true;
            for(int i=0;i<word.size();i++){
                if(word[i]!='.'&&word[i]!=x[i]){
                    b=false;
                    break;
                }
            }
            if(b) return b;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */