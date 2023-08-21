class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);

        TreeNode* new_root=new TreeNode(ans[0]);
        TreeNode* prev=new_root;
        for(int i=1;i<ans.size();i++){
            TreeNode* new_right_child=new TreeNode(ans[i]);
            prev->right=new_right_child;
            prev=new_right_child;
        }

        return new_root;
    }
};
