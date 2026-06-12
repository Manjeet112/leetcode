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
int maximum_value=0;
void dfs(TreeNode*root,vector<int>&path){
    if(root==NULL)return;
    path.push_back({root->val});
    if(root->left==NULL && root->right==NULL){
        maximum_value=max(maximum_value,(int)path.size());
    }
    dfs(root->left,path);
    dfs(root->right,path);
    path.pop_back();
}
    int maxDepth(TreeNode* root) {
        vector<int>path;
        dfs(root,path);
        return maximum_value;
    }
};