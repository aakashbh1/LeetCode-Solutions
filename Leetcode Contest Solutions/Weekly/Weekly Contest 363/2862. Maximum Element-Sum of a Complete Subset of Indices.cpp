class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        long long n=nums.size();
        vector<long long> sq;
        sq.push_back(1);
        long long curr=2;
        while(sq.back()<1e4)
        {
            sq.push_back(curr*curr);
            curr++;
        }
        long long ans=-1;
        for(long long i=0;i<n;i++)
        {
            long long currans=0;
            for(long long j=0;j<sq.size();j++)
            {
                if((i+1)*sq[j]-1>=n) break;
                currans+=nums[(i+1)*sq[j]-1];
            }
            ans=max(ans,currans);
        }
        return ans;
    }
};

//Approach 2
class Solution {
public:
    long long maximumSum(vector<int>& nums) { //tc -> O(N * sqrt(N))
        int n = nums.size();
        long long ans = 0;
        for(int i = 1; i <= n; i++){
            long long sum = 0;
            for(int j = 1; j * j <= n; j++){
                int ind = j * j * i;
                
                if(ind <= n){
                    sum += nums[ind - 1];
                }
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
