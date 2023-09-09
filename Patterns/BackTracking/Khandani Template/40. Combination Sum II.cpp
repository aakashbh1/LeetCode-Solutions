class Solution {
public:

    void solve(int index,vector<int>& candidates, int target,vector<vector<int>>& result,vector<int>& current)
    {
        if(target==0)
        {
            result.push_back(current);
            return;
        }

        if(target<0 || index>=candidates.size())
        {
            return;
        }

        for(int i=index;i<candidates.size();i++)
        {
            if(i>index && candidates[i]==candidates[i-1])
            {
                continue;
            }
            current.push_back(candidates[i]);
            solve(i+1,candidates,target-candidates[i],result,current);
            current.pop_back();
        }
    }
    /* Template 2 
     void helper(vector<int>& nums,int i, int target, vector<int> &comb, set<vector<int>> &result)
    { 
        if(i>=nums.size())
        {
            if(target==0)
            {
                result.insert(comb);
            }
            return;
        }

        comb.push_back(nums[i]); 
        helper(nums,i+1,target-nums[i],comb,result); //pick up an element
        comb.pop_back();
		
        helper(nums,i+1,target,comb,result); //non pick up an element
    }
    */

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int>current;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,result,current);
        return result;
    }
};
