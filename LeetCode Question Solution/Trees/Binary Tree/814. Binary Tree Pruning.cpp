class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
       if(!root)return NULL;
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        if(root->val==0){
            if(root->left|| root->right)return root;
            else{
                root=NULL;
                delete root;
                return NULL;
            }
        }
        else{
            return root;
        }
          
    }
};
