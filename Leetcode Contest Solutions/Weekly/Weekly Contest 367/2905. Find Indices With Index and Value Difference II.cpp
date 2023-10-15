class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int idx, int v) {
        set<pair<int,int>>st;
        for(int i=0;i<nums.size();i++)
        {
            if(i-idx<0)continue;
            st.insert({nums[i-idx],i-idx});
            
            auto val1=*st.begin();
            auto val2=*st.rbegin();
            
            if(abs(nums[i]-val1.first)>=v)
            {
                return {val1.second,i};
            }
            if(abs(nums[i]-val2.first)>=v)return {val2.second,i};
        }
        return {-1,-1};
    }
};
