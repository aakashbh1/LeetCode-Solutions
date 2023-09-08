class Solution {
public:
    bool binarySearch (vector<int> &arr, int l, int r, int target)
    {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] == target)
                return true;
            else if (arr[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return false;
    }
    
    bool checkIfExist(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++) {
            if((arr[i] % 2 == 0) && arr[i] < 0) {
                if(binarySearch(arr, i + 1, arr.size() - 1, arr[i] / 2))
                    return true; 
            }
            else {
                if (binarySearch(arr, i + 1, arr.size() - 1, 2 * arr[i]))
                    return true;
            }
        }
        return false;
    }
};
