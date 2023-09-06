class Solution {
public:
    // Global variable to store the limit
    int lim; 
    // DFS function that calculates the sum from root to that node in sum param 
    // and returns the max sum of paths below the current node
    int help(TreeNode* root, int sum=0)
    {
        // if the current node doesn't exist return a min value (can be INT_MIN)
        if(!root) return -1e9;
        
        // increment sum with current node's value
        sum+=root->val;
        
        // traverse left and right subtree and get their path sum
        int left =help(root->left,sum);
        int right=help(root->right,sum);
        
        // if sum from root to current node + the paths sum below current node is
        // less than the limit we delete the node
        // make sure to check if the left or substree exist
        if(root->left && sum+left <lim) root->left=nullptr;
        if(root->right&& sum+right<lim) root->right=nullptr;
        
        // if dead end of the path return current nodes value
        if(left==-1e9 && right==-1e9) return root->val;
        
        // else return the sum of current node + maximum of both the paths
        return root->val+max(left,right);
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        lim=limit;
        
        int head=help(root);
        // check if the path below root node has path sum less than limit
        // if lesser than return null else return root
        if(head<limit) return nullptr;
        
        return root;
    }
};
