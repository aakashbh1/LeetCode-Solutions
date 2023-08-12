class Solution {
public:
    int check(vector<int>&nums, int mid){
        int res=0;

        for(int i=0;i<nums.size();i++){
            res+=ceil((double)nums[i]/(double)mid);
        }
        return res;

    }
    int smallestDivisor(vector<int>& nums, int threshold) {
       int high=*max_element(nums.begin(),nums.end());
       int low=1;
       int ans=INT_MAX;
       while(low<=high){
           int mid=low+(high-low)/2;
           if(check(nums,mid)<=threshold){
               ans=mid;
               high=mid-1;
           }
           else low=mid+1;
       }
       return ans; 
    }

};
