class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unorderedd_map<int,int> mp;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])==1){
                count+=mp[nums[i]];
            }
            mp[nums[i]]++;
        }
        return count;
    }
};

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]==nums[i])count++;
            }
        }

        return count;
    }
};
