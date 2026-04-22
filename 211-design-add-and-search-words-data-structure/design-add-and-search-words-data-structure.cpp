class WordDictionary {
public:

    class TrieNode{
        public:
        char data;
        vector<TrieNode*> child;
        bool end;
        TrieNode(char val){
            data = val;
            child.assign(26 , NULL);
            end = false;
        }
    };
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode('\0');
    }
    
    void addWord(string word) {
        TrieNode * temp = root;
        int n = word.size();
        for(int i = 0; i < n; i++){
            int ind = word[i] - 'a';
            if(temp->child[ind] == NULL)
            temp->child[ind] = new TrieNode(word[i]);
            temp = temp->child[ind];
        }
        temp->end = true;
    }
    bool find(int ind , string &word , TrieNode* &temp){
        int n = word.size();
        bool ok = false;
        if(ind == n){
            return temp->end;
        }
        int i = word[ind]-'a';
        if(word[ind] == '.'){
            for(int j = 0; j < 26; j++){
                if(temp->child[j] != NULL){
                    TrieNode * tt = temp;
                    tt = tt->child[j];
                    ok |= find(ind+1, word , tt );
                }
            }
        }
        else if(temp->child[i] == NULL) return false;
        else {
            TrieNode * tt = temp;
            tt = tt->child[i];
            return find(ind+1, word , tt );
        }
        
        return ok;
    }
    bool search(string word) {
        TrieNode * temp = root;
        return find(0 , word , temp);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */