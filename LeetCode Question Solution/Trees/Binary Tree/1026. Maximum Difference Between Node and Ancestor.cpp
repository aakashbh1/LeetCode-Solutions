class Solution {
public:
    int findMaxDiff(TreeNode* root, int minValue, int maxValue){
        if(root==NULL) return abs(minValue-maxValue);
        minValue=min(minValue,root->val);
        maxValue=max(maxValue,root->val);
        int l=findMaxDiff(root->left, minValue,maxValue);
        int r=findMaxDiff(root->right,minValue,maxValue);
        return max(l,r);
    }
    int maxAncestorDiff(TreeNode* root) {
        return findMaxDiff(root, root->val,root->val);
    }
};
