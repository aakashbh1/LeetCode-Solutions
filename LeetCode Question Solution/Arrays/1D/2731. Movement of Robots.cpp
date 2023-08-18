class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int i = 0, n = nums.size();
        for(i = 0; i < n; i++){
            if(s[i]=='R'){
                nums[i] += d;
            }else{
                nums[i] -= d;
            }
        }
        sort(nums.begin(),nums.end());
        long long ans = 0,mod = 1e9+7,p = 0;
        for(i = 0; i < n; i++){
            ans = (((ans+(nums[i]*1LL*i)%mod)%mod-p)%mod+mod)%mod;
            p = (p+nums[i])%mod;
        }
        return (ans+mod)%mod;
    }
};
