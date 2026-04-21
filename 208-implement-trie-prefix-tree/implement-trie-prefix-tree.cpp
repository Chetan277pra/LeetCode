class Trie {
public:
    class TrieNode{
        public:
        char data;
        vector<TrieNode*> child;
       bool end;
        TrieNode(char ch){
            data = ch;
            end = false;
            child.resize(26 , NULL);
        }
    };
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }
    void insert(string word) {
        TrieNode* temp = root;
        int n = word.size();
        for(int i = 0; i < n; i++){
            int ind = word[i] - 'a';
            if(temp->child[ind] == NULL)
            temp->child[ind] = new TrieNode(word[i]);
            temp = temp->child[ind];
        }
        temp->end = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        int n = word.size();
        for(int i = 0; i < n; i++){
            int ind = word[i] - 'a';
            if(temp->child[ind] == NULL) return false;
            temp = temp->child[ind];
        }
        return temp->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        int n = prefix.size();
        for(int i = 0; i < n; i++){
            int ind = prefix[i] - 'a';
            if(temp->child[ind] == NULL) return false;
            temp = temp->child[ind];
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