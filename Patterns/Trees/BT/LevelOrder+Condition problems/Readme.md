These Problems as its base uses level order traveral but with just a small twist   
This twist can be any condition given ini question and we just need to use that condition 
inside normal level order travesal code template   


Pseduo Code:


      class Solution {
      public:
          vector<double> averageOfLevels(TreeNode* root) {
              vector<double> ans;
              queue<TreeNode*> q;
              q.push(root);
              while(!q.empty()){
                  int n=q.size();// size of queue
                  double res=0;
                  int count=0;
                  while(n--){ // till this level, n-- helps us to keep track of current as as n==0 then next level start   
                      TreeNode* temp=q.front();// fetching current element at top of queue  
                      q.pop(); // poping it    
                      res+=temp->val;
                      count++;  
      
                      if(temp->left) q.push(temp->left); // push root->left element in queue  
                      if(temp->right) q.push(temp->right);// push root->right element in queue    
                  }
                  ans.push_back(res/count); // some operation in Level order traversal  
              }
              return ans;
          }
      };

      for N-array tree level order traversal will be just one case differenr    

      inside while(n--){
         Node* tmp=q.front();
            q.pop();
            currlevel.push_back(tmp->val);
            for (auto x : tmp -> children) as each node have more than 2 children so just traversed to all and pushed in queue
            q.push(x);  // pushed in queue  
            }
