class Solution {
public:
    int f(int i, int j, vector<vector<int>>& dp, vector<int>& prices){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(j){
            return dp[i][j]=max((-1)*prices[i]+f(i+1, 0, dp, prices), f(i+1, 1, dp, prices));
        }
        else{
            return dp[i][j]=max(prices[i]+f(i+1, 1, dp, prices), f(i+1, 0, dp, prices));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return f(0, 1, dp, prices);
    }
};
