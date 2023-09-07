class Solution {
public:
    bool check(vector<int> candies, long long mid, long long k){

        long long count=0;
        for(auto x: candies){
            count+=x/mid;
        }
        if(count>=k) return true;
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
       int start=1;
        int end= *max_element(candies.begin(),candies.end());
        int ans=0;

        while(start<=end){
            int mid=start+(end-start)/2;
            if(check(candies,mid,k)){
                ans=mid;
                start=mid+1;
            }
            else {
                end=mid-1;
            }
        } 
        return ans;
    }
};
