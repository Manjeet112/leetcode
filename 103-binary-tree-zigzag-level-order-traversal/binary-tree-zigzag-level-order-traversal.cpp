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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        int flag=0;
        while(!q.empty()){
            int n=q.size();
            vector<int>level(n);
            for(int i=0;i<n;i++){
                TreeNode*node=q.front();
                q.pop();
                int index;
                if(flag==0){
                    index=i;
                }
                else{
                    index=n-1-i;
                }
                level[index]=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans.push_back(level);
            if(flag==0)flag=1;
            else flag=0;
        }
        return ans;
    }
};