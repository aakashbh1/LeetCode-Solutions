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
            for (auto x : tmp -> children) each node have n children stored in  (tmp->children Node* vector) so just traversed to all and pushed in queue
            q.push(x);  // pushed in queue  
            }


Using NULL value in queue to get idea of level end and starts
 used to print lecel order line by line    

      
             vector<vector<int> > levelOrder(TreeNode *root) {
              vector<vector<int> >  result;
              if (!root) return result;
              queue<TreeNode*> q;
              q.push(root);
              q.push(NULL);
              vector<int> cur_vec;
              while(!q.empty()) {
                  TreeNode* t = q.front();
                  q.pop();
                  if (t==NULL) { // new level is starting
                      result.push_back(cur_vec); // push previous levels answer in 2d vector
                      cur_vec.resize(0); // resize vector
                      if (q.size() > 0) {
                          q.push(NULL); // again push NULL if there are values inside the queue 
                      }
                  } else {
                      cur_vec.push_back(t->val); // push current value int current vector
                      if (t->left) q.push(t->left); // push into queue
                      if (t->right) q.push(t->right); // push into queue  
                  }
              }
              return result;
           }
          
Recusrive Level order 
               
                  class Solution {
                  public:
                      vector<vector<int>> ans;
          
                      void travel(TreeNode* root,int level){
                                if(!root)
                                    return; 
                                if(ans.size()==level) // nodes push karne se pehle usme empty vector bana diya for taaki values baad mei daal sake [level] as index
                                    ans.push_back({});// create new vector<int> {} an empty vector to store values in for new level 
                              // preorder traversal NLR
                                ans[level].push_back(root->val);// push roots value in vector according to the level in the function call
                                travel(root->left,level+1); // go left and increment level
                                travel(root->right,level+1); // go right and incement level
                            
                        }
     
                         vector<vector<int>> levelOrder(TreeNode* root) {
                             if(!root)
                                return {}; // return empty vector
                             travel(root,0); // function call 
                             return ans;  
         
                    }
                 };
