class Solution {        //LRN
public:
    int ans=0;
    int dfs(TreeNode* root){
        if(root==NULL) return 0;

        int left=dfs(root->left); // value from left subtree 
        int right=dfs(root->right); // value from right subtree 

        ans+=abs(left-right); // operation on node 
        return left+right+root->val;
    }
    int findTilt(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
