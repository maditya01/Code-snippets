struct TrieNode{
    TrieNode *children[26];
    bool isEnd;
};

class Trie {
private:
    TrieNode *root;
public:
    
    Trie() {
      root = getNode();//This Line is Important  
    }
    
    TrieNode* getNode(){
        TrieNode* nd = new TrieNode;//this line is important. we are creating a NODE 
      //Here we are Initialsing Value to that node.
        nd->isEnd = false;
        for(int i=0;i<26;i++){
            nd->children[i] = NULL;
        }        
        return nd;
    }
    
    void insert(string word) {
        TrieNode* tmp=root;
        for(int i=0;i<word.length();i++){
            int ind = word[i]-'a';
            if(tmp->children[ind] == NULL){
                tmp->children[ind] = getNode();
            }
            tmp = tmp->children[ind];
        }
        tmp->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* tmp=root;
        for(int i=0;i<word.size();i++){
            int ind=word[i]-'a';
            if(tmp->children[ind] == NULL) return false;
            tmp = tmp->children[ind];
        }
        return tmp->isEnd;
    }
    
    bool startsWith(string word) {
         TrieNode* tmp=root;
        for(int i=0;i<word.size();i++){
            int ind=word[i]-'a';
            if(tmp->children[ind] == NULL) return false;
            tmp = tmp->children[ind];
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
