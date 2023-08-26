class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            double res=0;
            int count=0;
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                res+=temp->val;
                count++;

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(res/count);
        }
        return ans;
    }
};
