// Recursion solution
// This is the recusive approach for solving the question:

class Solution {
private:

    // this has the same name as the original function but both are distinct as they require different number of arguments
    int search(vector<int>& nums, int target, int start, int end) {

        // start <= end is the necessary condition for binary search
        if (start>end) return -1;
        int mid = start + (end-start)/2;
        if (nums[mid]==target) return mid;

        // if the value is higher at mid of the subarray, and since the array is sorted, the value required shall be in the left half of the array
        else if (nums[mid] > target) return search(nums, target, start, mid-1);

        // the value is present in the right half of the array as the value at mid of current subarray is lower than needed
        else return search(nums, target, mid+1, end);
    }
public:
    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size()-1);
    }
};
// Iterative solution
// This is a better solution as it reduces the need of storage of stack memory

class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        
        int start = 0, end = nums.size()-1;

        while (start <= end) {
            int mid = start + (end - start)/2;
            if (nums[mid]==target) return mid;
            else if (nums[mid] < target) start = mid+1;
            else end = mid-1;
        }

        return -1;
    }
};
