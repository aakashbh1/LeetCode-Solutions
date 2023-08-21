class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        unordered_map<int,int> freq;
        for(int i=0,j=0,most=0;i<n;i++){
            most=max(most,++freq[nums[i]]);
            while(i-j-most>=k){
                freq[nums[j]]--;
                j++;
            }
            ans=max(ans,most);
        }
        return ans;
    }
};
