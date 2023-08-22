class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        int prev=root->val;

        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->val!=prev) return false;
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }

        return true;
    }
};
