class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low=0, high=letters.size()-1;
        while(low<=high){
            int mid = low + ((high-low)>>1);
            if(letters[mid]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low==letters.size()? letters[0] : letters[low];
    }
};

// 2nd Approach 
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = upper_bound(letters.begin(),letters.end(),target);
        return it!=letters.end()  ?*it:letters[0];
    }
};
