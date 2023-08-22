// 1325. Delete Leaves With a Given Value
class Solution {
public:
   TreeNode* removeLeafNodes(TreeNode* root, int target) {
        postorder(root,target);
        return root;
    }

    void postorder(TreeNode* &root,int target)
    {
        if(!root)return;
        postorder(root->left,target);
        postorder(root->right,target);
        if(root->val==target && root->left==NULL && root->right==NULL)
        {
            root=NULL;
        }
    }
};
