class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int rec(int idx,int left,vector<int> &cost,vector<int> &time)
    {
        if(left<=0) return 0;
        if(idx==n) return 1e9;
       
        if(dp[idx][left]!=-1) return dp[idx][left];
        int take = cost[idx] + rec(idx+1,left-1-time[idx],cost,time);
        int not_take = rec(idx+1,left,cost,time);
        
        return dp[idx][left] = min(take,not_take);
    }
    int paintWalls(vector<int>& cost, vector<int>& time)
    {
        n = cost.size();
     
        dp = vector<vector<int>> (n+1,vector<int>(n+1,-1));
        
        return rec(0,n,cost,time);
    }
};
