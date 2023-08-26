class Solution {
public:
   int s=0;// stores values of nodes that were previously visited
// this funtion perform reverse preorder
    void reverseInorder(TreeNode* root){
        if(!root) return;
        reverseInorder(root->right);
// current node's value is added to "s" to use it in next node
        s+=root->val;
        root->val=s;// updated current node with s
        reverseInorder(root->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        reverseInorder(root);
        return root;
    }
};
