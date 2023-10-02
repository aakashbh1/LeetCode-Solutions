#include<math.h>
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
         int n = nums.size();
        
    vector<int> prefix_maximum(n);
    prefix_maximum[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefix_maximum[i] = max(prefix_maximum[i - 1], nums[i]);
    }
    
    vector<int> suffix_maximum(n);
    suffix_maximum[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffix_maximum[i] = max(suffix_maximum[i + 1], nums[i]);
    }
    
    long long result = 0;
    
    for (int j = 1; j < n - 1; j++) {
        long long triplet_value = (long long)(prefix_maximum[j - 1] - nums[j]) * suffix_maximum[j + 1];
        result = max(result, triplet_value);
    }
    
    return result <= 0 ? 0 : result;
    }
};
