class Solution {
public:
     bool func(int m,vector<int>nums, int k){
        long long sum =0,totalsum=0,mid = m;
        int i =0;
        while(i<mid){
            sum+=nums[i];
            i++;
        }
        totalsum = mid * nums[mid-1];
        if(totalsum-sum <= k) return true;

        int j=0;
        for(int i = mid; i < nums.size();i++){
            sum+=nums[i];
            sum-=nums[j];
            totalsum= mid*nums[i];
            if(totalsum-sum <= k) return true;
            j++;
        }
        return false;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int low = 1, high = nums.size();int ans =1;
        while(low<= high){
            int mid = low + (high-low)/2;
            if(func(mid,nums,k)){
                low = mid+1;
                ans= mid;
            }
            else high = mid-1;
        }
        return ans;
    }
};
