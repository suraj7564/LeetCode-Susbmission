class Trie {
public:
    class Node{
        public:
        bool isEnd;
        Node* a[26];
        Node(){
            isEnd = false;
            for(int i=0;i<26;i++){
                a[i] = NULL;
            }
        }
    };
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *temp = root;
        for(int i=0;i<word.length();i++){
            if(temp->a[word[i]-'a']==NULL){
                Node *cur = new Node();
                temp->a[word[i]-'a'] = cur;
            }
            temp = temp->a[word[i]-'a'];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        Node *temp = root;
        for(int i=0;i<word.length();i++){
            if(temp->a[word[i]-'a']==NULL){
                return false;
            }
            temp = temp -> a[word[i]-'a'];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node *temp = root;
        for(int i=0;i<prefix.length();i++){
            if(temp -> a[prefix[i]-'a']==NULL) return false;
            temp = temp->a[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */