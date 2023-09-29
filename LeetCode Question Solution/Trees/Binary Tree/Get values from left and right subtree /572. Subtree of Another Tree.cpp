class Solution {
public:
    bool check(TreeNode* root, TreeNode* subRoot){
        if(root==NULL && subRoot==NULL) return 1;
        if(root==NULL || subRoot==NULL) return 0;
        if(root->val!=subRoot->val) return 0;
        bool left=check(root->left, subRoot->left);
        bool right=check(root->right, subRoot->right);

        return left&&right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return 0;
        if(check(root,subRoot)) return 1;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        
    }
};
