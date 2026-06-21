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
    int ans = 0;
    void rec(TreeNode* root, int & temp){
        if(!root) return ;
        temp = temp*10 + root->val;
        if(!root->left and !root->right) {
            ans += temp;
            temp /= 10;
            return;
        }
        rec(root->left , temp);
        rec(root->right, temp);
        temp /= 10;
    }
public:
    int sumNumbers(TreeNode* root) {
        int temp = 0;
        rec(root, temp);
        return ans;
    }
};