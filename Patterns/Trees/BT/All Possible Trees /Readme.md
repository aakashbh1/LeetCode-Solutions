 This type of questions require to get all possible binary tree or binary search tree or any other type of tree.
 This uses Dynamic Programming as its base and it also have a template

 Patter I am talking about in the solve function
 
  
 {

    for(int i = 1; i < n; i+=2){
      vector<TreeNode*>left = solve(i); // left subtrees trees 
      vector<TreeNode*>right = solve(n - i - 1);    // right subtrees    
            for( TreeNode*l: left) // iterating to all possibilities
            {
                for(TreeNode*r : right)
                {   
                    TreeNode* root = new TreeNode(0);    
                    root -> left = l;
                    root -> right = r; 
                    res.push_back(root);// pushing result
                }
            }
        }
          
        
}
