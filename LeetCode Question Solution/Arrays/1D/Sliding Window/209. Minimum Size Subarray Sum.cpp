class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int n=nums.size();
       int i=0;
       int j=0;
       int s=0;
        int res=INT_MAX;
        while(j<n){
            s=s+nums[j];
                if(s<target)j++;
            

            else{
                while(s>=target){
                    res=min(res,j-i+1);
                    s=s-nums[i];
                    i++;
                }

                j++;
            }
    }
        
        if(res==INT_MAX) return 0;
        return res;
    }
};
