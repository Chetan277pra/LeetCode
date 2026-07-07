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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;
        queue<pair<TreeNode* , long long>> q;
        q.push({root , 0});
        while(!q.empty()){
            long long n = q.size();
            long long f = INT_MAX;
            long long e = INT_MIN;
            long long mini = INT_MAX;
            for(int i = 0; i < n; i++){
                auto a = q.front(); q.pop();
                mini = min(mini , a.second);
                a.second -= mini;
                f = min(f , a.second);
                e = max(e , a.second);
                if(a.first->left)
                q.push({a.first->left ,2*a.second+1});
                if(a.first->right)
                q.push({a.first->right , 2*a.second+2});
            }
            ans = max(ans , e-f+1);
        }
        return (int)ans;
    }
};