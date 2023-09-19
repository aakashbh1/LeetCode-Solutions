class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int slow = nums[0];
       int fast = nums[0];
	  //Detecting the loop.
       do{
           slow = nums[slow];
           fast = nums[nums[fast]];
       }while(slow != fast);
		// Finding Start positon of the loop.
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x: nums){
            mp[x]++;
        }

        for(auto x: mp){
            if(x.second>=2) return x.first;
        }
        return -1;
    }
};
