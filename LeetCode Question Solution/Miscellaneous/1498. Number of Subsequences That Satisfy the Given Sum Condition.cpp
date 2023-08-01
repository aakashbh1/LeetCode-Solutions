// Binary Expontention +Two pointer
class Solution {
public:
    long long power(long long base,long long n, long long mod){
        long long ans=1;
         while(n!=0){
             if(n%2==1){
                 ans=(ans*base)%mod;
                 n--;
             }
             else {
                 base=(base*base)%mod;
                 n=n/2;
             }
         }

         return ans;

    }
    int numSubseq(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        sort(nums.begin(),nums.end());
        int mod=1e9+7;
        int count=0;
        while(start<=end){
            if(nums[start]+nums[end]<=target){
                long long totalsubseq=power(2,end-start,mod);
                count=(count+totalsubseq)%mod;
                start++; 
            }
            else end--;
        }
         return count;
    }

   
};


// Precomputuation+Two Pointers 
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int res = 0, mod = 1000000007, l = 0, r = nums.size() - 1;
        vector<int> pre = {1};
        for (auto i = 1; i <= nums.size(); ++i)
            pre.push_back((pre.back() << 1) % mod);   
                
        sort(begin(nums), end(nums));
        
        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                r--;
            } else {
                res = (res + pre[r - l++]) % mod;
            }
        }

        return res;
    }
};
