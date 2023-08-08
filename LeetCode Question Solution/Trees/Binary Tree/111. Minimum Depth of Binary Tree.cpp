class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int left=minDepth(root->left);
        int right=minDepth(root->right);
        if(left==0)return 1+right;
        else if(right==0) return 1+left;
        else return 1+ min(left,right);
    }
};
