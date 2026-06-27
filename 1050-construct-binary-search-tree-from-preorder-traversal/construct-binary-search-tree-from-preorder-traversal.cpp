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
TreeNode*slavic( TreeNode*root,int val){
    TreeNode*curr=root;
    while(true){
        if(curr->val>val){
            if(curr->left==NULL){
            curr->left=new TreeNode(val);
            break;
        }
        curr=curr->left;
    }else{
        if(curr->right==NULL){
            curr->right=new TreeNode(val);
            break;
        }
        curr=curr->right;
    }
}
return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode*root=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
        slavic(root,preorder[i]);
        }
        return root;
    }
};