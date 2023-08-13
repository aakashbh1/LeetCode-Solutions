class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int target) {
        int n = nums.size();
        int m=nums.size();
        int result = INT_MAX;
        set<int> valueSet;
        int maxiValue = INT_MIN;
        for(int i=n-1;i>=0;i--){
            valueSet.insert(nums[i]);
            maxiValue = max(maxiValue, nums[i]);
            if(i - target >= 0 && maxiValue >= nums[i - target]){
                int a = nums[i - target];
                auto b = valueSet.lower_bound(a);
                if(b != valueSet.end()) result = min(result, abs(*b - a));
            }
        }
        maxiValue = INT_MIN;
       valueSet.clear();
        for(int i=0;i<n;i++){
            valueSet.insert(nums[i]);
            maxiValue = max(maxiValue, nums[i]);
            if(i + target < n && maxiValue >= nums[i + target]){
                int a = nums[i + target];
                auto b = valueSet.lower_bound(a);
                if(b != valueSet.end()) result = min(result, abs(*b - a));
            }
        }
        return result;
        
    }
};
