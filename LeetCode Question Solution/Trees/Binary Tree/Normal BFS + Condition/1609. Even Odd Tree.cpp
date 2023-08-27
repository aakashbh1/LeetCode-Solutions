/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int s = q.size();
            int prev;
            if(level % 2 !=0)
                prev=INT_MAX;
            else
                prev=INT_MIN;
            for(int i=0;i<s;i++){
                TreeNode* node = q.front();
                if(level % 2 == node->val % 2)
                    return false;

                if((level % 2 !=0) && (prev <= node->val))
                    return false;
                if((level % 2 ==0) && (prev >= node->val))
                    return false;

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);

                 prev = node->val;
                 q.pop(); 
            }
            ++level;
        }
        return true;
    }
};
