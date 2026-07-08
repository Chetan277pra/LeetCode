/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void rec(TreeNode* root , vector<int>& in){
        if(!root) return;
        rec(root->left , in);
        in.push_back(root->val);
        rec(root->right , in);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> in;
        rec(root , in);
        return in[k-1];
    }
};