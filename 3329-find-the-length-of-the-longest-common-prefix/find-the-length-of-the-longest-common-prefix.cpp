class Solution {
public:
    class TriesNode{
        public:
        char data;
        vector<TriesNode *> child;
        bool isend;
        TriesNode(char val){
            data = val;
            child.assign(10 , NULL);
            isend = true;
        }
    };
    class Tries{
        public:
        TriesNode* root;
        Tries(){
            root = new TriesNode('\0');
        }
        void build(string s){
            int n = s.length();
            TriesNode *rr = root;
            for(int i = 0; i < n; i++){
                int temp = s[i] - '0';
                if(rr->child[temp] == NULL) 
                rr->child[temp] = new TriesNode(s[i]);
                rr = rr->child[temp];
            }
            rr->isend = true;
        }
        int longest(string s){
            int n = s.length();
            int len = 0;
            TriesNode * rr = root;
            for(int i = 0; i < n; i++){
                int temp = s[i] - '0';
                if(rr->child[temp] == NULL) break;
                len++;
                rr = rr->child[temp];
            }
            return len;
        }
    };

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Tries * tt;
        tt = new Tries();
        for(auto a : arr1){
            string t = to_string(a);
            tt->build(t);
        }
        int ans = 0;
        for(auto a : arr2){
            string t = to_string(a);
            ans = max(ans , tt->longest(t));
        }
        return ans;
    }
};
