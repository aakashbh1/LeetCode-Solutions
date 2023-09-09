//T.C : O(N*target)
class Solution {
public:
    int n;
    int t[1001][201];
    int solve(vector<int>& nums, int target, int idx) {
        if(target == 0)
            return 1;
        
        if(idx >= n || target < 0)
            return 0;
        
        if(t[target][idx] != -1)
            return t[target][idx];
        
        int take_idx    = solve(nums, target - nums[idx], 0);
        int reject_idx  = solve(nums, target, idx+1);
        
        return t[target][idx] = take_idx + reject_idx;
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        
        return solve(nums, target, 0);
    }
};

//Approach-2 (Same backtracking + but just using for loop)
//T.C : O(N*target)
class Solution {
public:
    int n;
    int t[1001][201];
    
    int solve(int idx, vector<int>& nums, int target) {
        if(target == 0)
            return 1;
        
        if(idx >= n || target < 0)
            return 0;
        
        int result = 0;
        
        if(t[target][idx] != -1)
            return t[target][idx];
        
        for(int i = idx; i<n; i++) {
            int take_i   = solve(0, nums, target-nums[i]);
            
            result += take_i;
        }
        
        return t[target][idx] = result;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, nums, target);
    }
};

//Approach-3 (In Approach-2 above, you can see that we no longer need to pass idx BECAUSE the for loop always starts from 0)
//So, remove idx from parameter
//T.C : O(N*target)
class Solution {
public:
    int n;
    int t[2001];
    
    int solve(vector<int>& nums, int target) {
        if(target == 0)
            return 1;
        
        if(target < 0)
            return 0;
        
        int result = 0;
        
        if(t[target] != -1)
            return t[target];
        
        for(int i = 0; i<n; i++) {
            int take_i   = solve(nums, target-nums[i]);
            
            result += take_i;
        }
        
        return t[target] = result;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, target);
    }
};


