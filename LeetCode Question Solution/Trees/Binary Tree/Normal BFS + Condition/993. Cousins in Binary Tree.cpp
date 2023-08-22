class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {       
        queue<pair<TreeNode*,int>> q;
        int tempParent;
        q.push({root,-1});

        while(!q.empty()){
            int count=0;
            int n=q.size();
            while(n--){
                TreeNode* temp=q.front().first;
                int parent=q.front().second;
                q.pop();
                if(temp->val==x || temp->val==y){
                    count++;
                    if(count==1) tempParent=parent;
                    if(count==2){
                        if(tempParent==parent) return false;
                        else return true;
                    }
                }
                if(temp->left) q.push({temp->left,temp->val});
                if(temp->right) q.push({temp->right,temp->val});
            }
            if(count==1) return false;
        }


        return true;
    }
};
