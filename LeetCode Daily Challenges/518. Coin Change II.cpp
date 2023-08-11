MEMOIZATION

class Solution {
public:
    vector<vector<int>>dp;
    int memo(int amount,int ind,vector<int>&coins){
        if(amount == 0)return 1;
        if(ind < 0 || amount < 0)return 0;
        if(dp[ind][amount] != -1) return dp[ind][amount];
        
        int pick = memo(amount - coins[ind],ind,coins);
        int notpick = memo(amount,ind-1,coins);

        return dp[ind][amount] = pick + notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(n+1,vector<int>(amount+1,-1));
        return memo(amount,n-1,coins);
    }
};
TABULATION

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));   
        
        for(int i=0;i<=n;i++)dp[i][0] = 1; 

        for(int i=1; i<=n;i++){
            for(int j=0;j<=amount;j++){
                int pick = 0, notpick = dp[i-1][j];
                if(coins[i-1] <= j)pick = dp[i][j - coins[i-1]];
                dp[i][j] = pick + notpick;
            }
        }
        return dp[n][amount];
    }
};
SPACE OPTIMIZED

class Solution {
public:
    //Space optimazation using 2 rows
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int>dp(amount+1,0);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            vector<int>curr(amount+1);
            for(int j=0;j<=amount;j++){
                int pick = 0, notpick = dp[j];
                if(coins[i-1] <= j)pick = curr[j-coins[i-1]];
                curr[j] = pick + notpick;
            }
            dp=curr;
        }
        return dp[amount];
    }
};
