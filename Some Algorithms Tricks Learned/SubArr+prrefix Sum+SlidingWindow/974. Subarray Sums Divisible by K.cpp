class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefixsum=0;
        map<int,int> mp;
        int ans=0;
        mp[0]=1;
        
        for(int i=0;i<nums.size();i++)
        {
            prefixsum+=nums[i];
            int rem=(prefixsum % k);
            if(rem<0)   rem+=k;
            ans+=mp[rem];
            mp[rem]++;
        }

        return ans;
    }
};
