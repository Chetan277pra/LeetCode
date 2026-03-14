/*
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
    void lvl(TreeNode* root , vector<vector<int>>&ans){
        queue<TreeNode*> q;
        if(root)
        {q.push(root);
        q.push(NULL);}
        vector<int> temp;
        while(!q.empty()){
        TreeNode* tt = q.front();
        q.pop();
        if(tt == NULL){
            ans.push_back(temp);
            if(!q.empty()) q.push(NULL);
            temp.clear();
            continue;
        }
        temp.push_back(tt->val);
        if(tt->left) q.push(tt->left);
        if(tt->right) q.push(tt->right);
        }
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        lvl(root , ans);
        return ans;
    }
};























