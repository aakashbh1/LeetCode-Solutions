class Solution {
public:
    int rank(vector<int>& nums, int dis) {
        int count=0, lo=0, hi=1;
        while(hi<nums.size()) {
            while(nums[hi]-nums[lo] > dis)
                lo++;
            count += hi-lo;
            hi++;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int left=0, right=nums[nums.size()-1]-nums[0];
        while(left<right) {
            int mid=left+(right-left)/2;
            if(rank(nums, mid) < k)
                left=mid+1;
            else
                right=mid;
        }
        return left;
    }
};
/*
 while(l<=r)
        {
            int mid = (l+r)/2;
            int cnt = solve(nums,k,mid);
            if(cnt>=k)
            {
                ans = mid;
                r = mid-1;
            }
            else
            l = mid+1;
        }
        return ans;
    }
*/
