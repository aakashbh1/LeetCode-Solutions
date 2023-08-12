class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        while(!q.empty()){
            int l=q.size();
            sum=0;
            for(int i=0;i<l;i++){
                root=q.front();
                sum+=root->val;
                q.pop();
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
        }


        return sum;

    }
};
