/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans = 0;

    // {isBST, minValue, maxValue, sum}
    array<int,4> rec(TreeNode* root) {

        if (!root)
            return {1, INT_MAX, INT_MIN, 0};

        auto l = rec(root->left);
        auto r = rec(root->right);

        if (l[0] && r[0] && l[2] < root->val && root->val < r[1]) {
            int sum = l[3] + r[3] + root->val;
            ans = max(ans, sum);
            return {1, min(l[1], root->val), max(r[2], root->val), sum };
        }
        return {0, INT_MIN, INT_MAX, 0};
    }

    int maxSumBST(TreeNode* root) {
        rec(root);
        return ans;
    }
};