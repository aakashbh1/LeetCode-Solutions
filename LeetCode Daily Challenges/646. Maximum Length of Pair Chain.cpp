Recursive
   int solve( int ind, vector<vector<int>>&pairs, int prev){
        if(ind>=pairs.size()) return 0;
        int take=0;
        if(prev==-1 || pairs[prev][1]<pairs[ind][0] )
            take=1+solve(ind +1, pairs, ind);
        
        int notTake=0+solve(ind+1, pairs, prev);

        return max(take,notTake);
      
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        return solve(0,pairs,-1);
    }
Memoization (Top-Down)
int solveMemo( int ind, vector<vector<int>>&pairs, int prev,vector<vector<int>> &dp){
        if(ind>=pairs.size()) return 0;
        int take=0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        if(prev==-1 || pairs[prev][1]<pairs[ind][0] )
            take=1+solve(ind +1, pairs, ind,dp);
        
        int notTake=0+solve(ind+1, pairs, prev,dp);

        return dp[ind][prev+1]=max(take,notTake);
      
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return solveMemo(0,pairs,-1,dp);
    }
Tabulation(Bottom-Up)
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int take=0;
                if(j==-1|| pairs[j][1]<pairs[i][0] )
                take=1+dp[i+1][i+1];
                int notTake=0+dp[i+1][j+1];
                dp[i][j+1]=max(take,notTake);
            }

        }  
        return dp[0][0];
    }
Space Optimized
int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> prev(n+1,0),curr(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int take=0;
                if(j==-1|| pairs[j][1]<pairs[i][0] )
                take=1+prev[i+1];
                int notTake=0+prev[j+1];
                curr[j+1]=max(take,notTake);
            }
            prev=curr;
        }  
        return prev[0];
    }
