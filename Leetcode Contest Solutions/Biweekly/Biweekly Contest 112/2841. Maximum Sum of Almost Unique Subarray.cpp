class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) { 
        unordered_map<int,int> mp;
        long long res=0;
        int i=0,j=0;
        long long tmp=0;
        while(j<nums.size())
        {
            tmp+=nums[j];
            mp[nums[j]]++;
            while(j-i+1>k)
            {
                mp[nums[i]]--;
                tmp-=nums[i];
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            if(j-i+1==k)
            {
                if(mp.size()>=m)
                    res=max(res,tmp);
            }
            j++;
        }
        return res;
    
    }
};
