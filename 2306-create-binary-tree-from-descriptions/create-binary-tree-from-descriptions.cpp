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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        map<int , TreeNode*> mpp;
        vector<bool> parent(1e5+1 , false);
        TreeNode* ans;
        for(auto a : desc){
            // left
            if(a[2] == 1){
                if(mpp.find(a[0]) == mpp.end()  and mpp.find(a[1]) == mpp.end() ){
                    TreeNode *temp1 = new TreeNode(a[0]);
                    TreeNode *temp2 = new TreeNode(a[1]);
                    temp1->left = temp2;
                    mpp[a[0]] = temp1; 
                    mpp[a[1]] = temp2;
                }
                else if(mpp.find(a[0]) == mpp.end()){
                    TreeNode * temp1 = new TreeNode(a[0]);
                    temp1->left = mpp[a[1]];
                    mpp[a[0]] = temp1; 
                }
                else if(mpp.find(a[1]) == mpp.end()) {
                    TreeNode * temp2 = new TreeNode(a[1]);
                    mpp[a[0]]->left = temp2;
                    mpp[a[1]] = temp2;
                }
                else{
                    mpp[a[0]]->left = mpp[a[1]];
                }
            }
            else{
                if(mpp.find(a[0]) == mpp.end()  and mpp.find(a[1]) == mpp.end() ){
                    TreeNode * temp1 = new TreeNode(a[0]);
                    TreeNode * temp2 = new TreeNode(a[1]);
                    temp1->right = temp2;
                    mpp[a[0]] = temp1; mpp[a[1]] = temp2;
                }
                else if(mpp.find(a[0]) == mpp.end()){
                    TreeNode * temp1 = new TreeNode(a[0]);
                    temp1->right = mpp[a[1]];
                    mpp[a[0]] = temp1;
                }
                else if(mpp.find(a[1]) == mpp.end()) {
                    TreeNode * temp2 = new TreeNode(a[1]);
                    mpp[a[0]]->right = temp2;
                    mpp[a[1]] = temp2;
                }
                else{
                    mpp[a[0]]->right = mpp[a[1]];
                }
            }
            parent[a[1]] = true;
        }
        for(auto a : mpp){
            if(!parent[a.first]) return a.second;
        }
        return ans;
    }
};