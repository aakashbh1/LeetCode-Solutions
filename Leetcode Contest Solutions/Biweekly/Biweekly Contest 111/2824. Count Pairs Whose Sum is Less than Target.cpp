// 2824. Count Pairs Whose Sum is Less than Target
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int count=0;
        
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]<target) count++;
            }
        }
        
        return count;
    }
};

//OPTIMISED
sort(nums.begin(), nums.end());
            int ans = 0;
    int n = nums.size();
    int l = 0, h = n - 1;
    while (l < h) {
        if (nums[l] + nums[h] < target) {
            ans += h - l;
            l++;
        } else {
            h--;
        }
    }
    
    return ans;
    }
