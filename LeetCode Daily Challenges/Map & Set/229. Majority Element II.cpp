class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        
        unordered_map<int,int> mp;
        for(auto &it:nums)
        {
            mp[it]++;
        }
        
        for(auto i:mp)
        {
            if(i.second>nums.size()/3)
                ans.push_back(i.first);
        }
        
        return ans;
    }
};
