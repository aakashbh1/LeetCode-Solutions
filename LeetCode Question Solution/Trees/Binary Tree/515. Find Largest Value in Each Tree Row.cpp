class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        
        int maxi=INT_MIN;
        vector<int> ans;
        queue<TreeNode*>q;
        if(root==NULL) return {};
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            maxi=INT_MIN;
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                maxi=max(maxi, temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);

            }
            ans.push_back(maxi);

        }

        return ans;

    }
};
