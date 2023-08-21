class Solution {
public:
    int mini=INT_MAX;
    int prev=-1;
    void inorder(TreeNode* root){
        if(root!=NULL){
            inorder(root->left);
            if(prev==-1){
                prev=root->val;
            }
            else{
                mini=min(root->val-prev,mini);
                prev=root->val;
            }
            inorder(root->right);
        }
    }
    int minDiffInBST(TreeNode* root) {
        if(root==NULL or (root->left==NULL and root->right==NULL)) return 0;
        inorder(root);
        return mini;
    }
};
