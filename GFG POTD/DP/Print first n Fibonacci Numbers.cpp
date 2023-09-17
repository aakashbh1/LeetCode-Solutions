long long int solve(int n, vector<long long int> &dp){
        if(n<0) return 0;
        if(n==0) return 1;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }
    vector<long long> printFibb(int n) 
    {
        //code here
        vector<long long int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        solve(n,dp);
        dp.pop_back(); 
        return dp;
    }
