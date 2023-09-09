class Solution {
public:
    void pick(int i,vector<int>& candidates,vector<vector<int>>&ans,vector<int>&v, int n,int target)
    {
        if(i==n)
        {
            if(target==0)
        {
            ans.push_back(v);
        }
            return;

        }
        if(candidates[i]<=target)
        {
        v.push_back(candidates[i]); //element lo 
        pick(i,candidates,ans,v,n,target-candidates[i]); // explore karo 
        v.pop_back(); // elment pop back karo
        }
        pick(i+1,candidates,ans,v,n,target); // ab uske bina explore karo 

        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n= candidates.size();
        vector<vector<int>>ans;
        vector<int>v;
        pick(0,candidates,ans,v,n,target);
        return ans;



        
    }
};

// using For Loop 
//temaplte 2
class Solution {
public:
    void helper(vector<int>& candidates, vector<int>& temp, int sum, int indx, int target, vector<vector<int>>& ans) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }

        for (int i = indx; i < candidates.size(); i++) {
            if (sum + candidates[i] <= target) {
                temp.push_back(candidates[i]);
                helper(candidates, temp, sum + candidates[i], i, target, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(candidates, temp, 0, 0, target, ans);
        return ans;
    }
};
