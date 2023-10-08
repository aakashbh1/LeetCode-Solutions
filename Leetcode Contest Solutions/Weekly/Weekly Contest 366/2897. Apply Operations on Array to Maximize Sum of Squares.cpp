typedef long long int ll;
const int MOD = 1e9+7;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(31, 0);
        
        for (int bit = 0; bit < 31; bit ++) {
            for (int j = 0; j < n; j ++) 
                if (nums[j] & (1 << bit)) cnt[bit] ++;
        }
        
        ll result = 0;
        
        for (int i = 0; i < k; i ++) {
            ll val = 0;
            
            for (int bit = 0; bit < 31; bit ++) {
                if (cnt[bit] < (i+1)) continue;
                val |= (1 << bit);
            }
            result = (result + val*val) % MOD;
        }
        return result;
    }
};
