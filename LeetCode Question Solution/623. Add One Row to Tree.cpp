class Solution {
public:
    void dfs(TreeNode* root, int curr_depth, int depth, int val){
        if(root==NULL) return;
        if(curr_depth==depth-1){
            TreeNode* prev_left=root->left;
            TreeNode* prev_right=root->right;

            TreeNode* new_node_left=new TreeNode(val);
            TreeNode* new_node_right=new TreeNode(val);
            root->left=new_node_left;
            root->right=new_node_right;

            root->left->left=prev_left;
            root->right->right=prev_right;
            return;
        }
        dfs(root->left, curr_depth+1, depth, val);
        dfs(root->right, curr_depth+1, depth, val);

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL) return NULL;
        if(depth==1){
            TreeNode* new_node=new TreeNode(val);
            new_node->left=root;
            return new_node;
        }
        dfs(root,1,depth,val);
        return root;
    }
};
