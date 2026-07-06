
class Solution {
  public:
    map<int , int > mpp;
    void rec(TreeNode* root , int row){
        if(!root) return;
        mpp[row] = root->val;
        rec(root->left , row+1 );
        rec(root->right , row+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        // code here
        if(!root) return {};
        vector<int> ans;
        rec(root , 0);
        for(auto a : mpp)
         ans.push_back(a.second);
        return ans;
    }
};