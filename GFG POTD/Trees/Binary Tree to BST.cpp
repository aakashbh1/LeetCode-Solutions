class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void inorder(Node* root, vector<int> &ans){
         if(root==NULL) return;
        inorder(root->left, ans);
       
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    int i=0;
    void dfs(Node* root, vector<int>& ans){
         if(root==NULL) return;
        dfs(root->left, ans);
      
        root->data=ans[i];
        i++;
        dfs(root->right,ans);
    }
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int> ans;
        inorder(root,ans);
        sort(ans.begin(),ans.end());
        dfs(root,ans);
        return root;
    }
};
