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
    int rec(TreeNode* root , int & ans){

        if(!root) return 0;

        int left = 0;
        left = max(left , rec(root->left , ans) );
        int right = 0;
        right = max(right , rec(root->right , ans));

        ans = max(ans , root->val + left + right);
        return root->val + max(left , right);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root->left and !root->right) return root->val;
        int ans = INT_MIN;
        rec(root , ans );
        return ans;
    }
};