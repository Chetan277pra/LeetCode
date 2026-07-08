/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* rec(TreeNode* root , TreeNode* p , TreeNode*q){
        if(!root) return nullptr;
        if(root == p or root == q) return root;
        TreeNode* l = rec(root->left , p , q );
        TreeNode* r = rec(root->right , p , q);
        if(l and r) return root;
        return l ? l : r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return rec(root , p , q);
    }
};