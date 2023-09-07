lass Solution {
public:
    void preorder(TreeNode* root,int &ans){
        if(root==NULL) return ;
        preorder(root->left,ans);
        ans=ans+1;
        preorder(root->right,ans);
    }
    int countNodes(TreeNode* root) {
        int ans=0;
        preorder(root,ans);
        //if(root->left==NULL&&!root->right==NULL) return 1;
        return ans;
    }
};
