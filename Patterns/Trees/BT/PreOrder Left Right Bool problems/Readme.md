So these type of problems are very very fequetly asked on leetcode 
in these kind of problem you will find out that you need to return 
true or false as an answer and the answer may be hidden in left subtree  
or right subtree of the main tree  

At every node you will need to get the result from its left and right subtree   
and evaluate accordingly to your need. I mean to say call funtion to node->left   
and to node->right and you will get 0/1 from both the side according to code 


Pseudo Code: We use Preorder method in these type of problems that it Node->left->right   


          // base cases if root is null or any kind of base cases   
          // call function to its left   
          // call function to its right  
          // return their "&&" or "||"  accordingly   

          Examples of Code:
          bool isSameTree(TreeNode* p, TreeNode* q) {
              if(!p && !q) return 1; // base case 
              if(!p || !q) return 0; // base case 
              
              if(p->val!=q->val) return 0; // Node
              
              bool left = isSameTree(p->left, q->left); // left // we can see we stored in bool left
              bool right = isSameTree(p->right, q->right);// right // we stored result in bool right 
              
              return left&right;  // operation needed to get the result can be "and" / "or 
              
              // this is same tree so here every node must be equal left and right every node so its "&&"
              // there is another way to write these last three lines also 
  
              return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); 
              // it includes all three last lines and works same
          }


          Another Example: 
           bool isSubtree(TreeNode* root, TreeNode* subRoot) {
               if (!root || !subRoot)
                return false; // ya yeh return hoga 
            
               if (isSameTree(root, subRoot))
                return true; // ya yeh return hoga 

                // ya fir yeh return hoga depends kaun condition hold kar rha hai  
               return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);     
               // here we used or because we just need to know if it is present or not 
               // like if it is in left or right we just want to know in anyone of them so we used "or"

          }
        
          
