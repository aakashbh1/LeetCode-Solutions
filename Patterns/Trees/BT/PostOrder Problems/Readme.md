So in this kind of problems we are given a tree and while making the algorithm to solve it   
we will find that we need to get value from left subtree and value from right subtree   
and do operation on the node we are on, so simply we will do use post order in which 
we will first get value from left and then from right and then we will simply 
perform operation which is required for the given question    

Pseudo Code :


          if(root==NULL) return 0/ return;  
          int left = fun(root->left, other parameters if any) // value from left subtree  
          int right= fun(root->right, other parameters if any) // value from right subtree   
          
          // now perform operation which ever is needed
          
          ans+=abs(left-right); // operation in the question    
          return left+right+root->val; // every node acts as either left or right for another so it return to its parent    
          // this return just returns this value to its parent element which will be stored in varaiable "left" or "right"

                   




          
