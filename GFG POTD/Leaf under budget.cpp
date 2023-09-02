class Solution
{
public:
     vector<int> leafNodeCost;
    
    void leafC(Node* root,int k){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL) leafNodeCost.push_back(k) ;
        leafC(root->left,k+1);
        leafC(root->right,k+1);
    }
    int getCount(Node *root, int k)
    {
        //code here
        leafC(root,1);
        sort(leafNodeCost.begin(),leafNodeCost.end());
        int count=0;
        for(auto x:leafNodeCost) {
            if(k-x>=0) {
                count++;
                k=k-x;
            }
            
            
        }
        
        return count;
    }
};
