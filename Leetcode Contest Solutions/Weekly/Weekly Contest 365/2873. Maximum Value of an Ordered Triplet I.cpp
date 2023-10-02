class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
     long long   int n = nums.size();
    // long long int max_val = INT_MIN;
   long long int max_triplet_val = INT_MIN;

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                long long int temp = static_cast<long> (nums[i] - nums[j]) * static_cast<long> (nums[k]);
                max_triplet_val = (temp > max_triplet_val) ? temp : max_triplet_val;
            }
        }
    }

    return max_triplet_val > 0 ? max_triplet_val : 0;
    }
};
