class Solution {
public:
    int solve(int ind,int last,vector<int> & nums,vector<int>&dp){
        if(ind>last) return 0;

        if(dp[ind]!=-1) return dp[ind];
        int take=nums[ind]+solve(ind+2,last,nums,dp);
        int notTake=0+solve(ind+1,last,nums,dp);

        return dp[ind]=max(take,notTake);
    }

    //TABULATION
    int solveTab(vector<int> & nums){
        int n=nums.size();

        vector<int>dp1(n+3,0);
        vector<int>dp2(n+3,0);

        for(int i=n-2;i>=0;i--){
            int take=nums[i]+dp1[i+2];
            int notTake=0+dp1[i+1];
            dp1[i]=max(take,notTake);
        }
        int res1=dp1[0];

        for(int i=n-1;i>=1;i--){
            int take=nums[i]+dp2[i+2];
            int notTake=0+dp2[i+1];
            dp2[i]=max(take,notTake);
        }
        int res2=dp2[1];

        return max(res1,res2);
    }
    // SPACE OPTIMISED

    int solveSO(vector<int> &nums){
        int n=nums.size();
        int prev1=0;
        int prev2=0;
        int next1=0;
        int next2=0;

        for(int i=n-2;i>=0;i--){
            int take=nums[i]+next1;
            int notTake=0+prev1;
            int curr1=max(take,notTake);
            next1=prev1;
            prev1=curr1;
        }
        int ans1=prev1;

        for(int i=n-1;i>=1;i--){
            int take=nums[i]+next2;
            int notTake=0+prev2;
            int curr2=max(take,notTake);
            next2=prev2;
            prev2=curr2;
        }

        int ans2=prev2;

        return max(ans1,ans2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        // vector<int>dp1(n+3,-1);
        // vector<int>dp2(n+3,-1);
        // int ans1=solve(0,n-2,nums,dp1);
        // int ans2=solve(1,n-1,nums,dp2);
        // return max(ans1,ans2);
       // return solveTab(nums);
       return solveSO(nums);
    }
};
