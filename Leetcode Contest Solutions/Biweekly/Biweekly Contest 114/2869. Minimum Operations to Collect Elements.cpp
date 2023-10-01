class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(int i=1;i<=k;i++){
            s.insert(i);
        }
        int res=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(s.count(nums[i])){
                s.erase(nums[i]);
            }
            res++; 
            if(s.empty()) break;
        }
        return res;
    }
};
