class Solution {
public:
    int findMin(vector<int>& nums) {
       int l=0;
       int r=nums.size()-1;
       while(l<r){
           int mid=l+(r-l)/2;
           if(nums[mid]>nums[r]) l=mid+1; //mid cant be a answer in this case
           else r=mid;// mid can be a answer
       } 
       return nums[r];
    }
};
