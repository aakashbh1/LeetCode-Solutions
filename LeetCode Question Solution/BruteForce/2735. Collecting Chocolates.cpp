class Solution {
public:
    
    void rotate(vector<int>& nums) {
        int n = nums.size();
        int last = nums[n-1];
        for(int i = n-1; i > 0; i--) 
            nums[i] = nums[i-1];
        nums[0] = last;
    }
    
    long long minCost(vector<int>& nums, int x) {
        
        long long cost = 0;
        int n = nums.size();
        vector<long long> res(n);
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            res[i] = nums[i];
            sum += res[i];
        }
        
        long long fans = sum;
        
        for(int r = 1; r <= n-1; r++) {
            cost += x;
            rotate(nums);
            // for(auto it: nums) cout << it << " "; cout << endl;
            long long ans = 0;
            for(int i = 0; i < n; i++) {
                res[i] = min(res[i], (long long)nums[i]);
                ans += res[i];
            }
            
            fans = min(ans + cost, fans);
        }
        
        return fans;
    }
};
