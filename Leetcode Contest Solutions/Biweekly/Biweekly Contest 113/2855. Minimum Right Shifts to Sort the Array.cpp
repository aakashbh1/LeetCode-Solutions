class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int count=0;
        int n=nums.size()-1;
        if(nums[0]<nums[nums.size()-1]){
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]>nums[i+1]) count++;
            }
            
            if(count>=1) return -1;
            if(count==0) return 0;
        }
        
        int ans=0;
        if(nums[0]>nums[n]){
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]>nums[i+1]) 
                {
                    count++;
                    ans=i;
                }
            }
            
            if(count>1) return -1;
            
        }
        
        return n-ans;
        
        
        
        
    }
};
