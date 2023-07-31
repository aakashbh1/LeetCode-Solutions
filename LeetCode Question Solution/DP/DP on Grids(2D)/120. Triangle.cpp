// Memoization Approach
// Time Complexity : O(NM)
// Space complexity: O(NM)+O(M)

int solve(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i==n-1) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int ind0=triangle[i][j]+solve(i+1,j,n,triangle,dp);
        int ind1=triangle[i][j]+solve(i+1,j+1,n,triangle,dp);
        return dp[i][j]=min(ind0,ind1);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,0,n,triangle,dp);
        
    }


// Tabulation Method
// Time Complexity : O(NM)+O(M)
// Space complexity: O(NM)

int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int dp[n][n];
        for(int j=0;j<n;j++) dp[n-1][j]=triangle[n-1][j];
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int ind0=triangle[i][j]+dp[i+1][j];
                int ind1=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(ind0,ind1);
            }
        }
        return dp[0][0];
    }


// Space Optimization
// Time Complexity : O(N*M)+O(M)
// Space complexity: O(N)

int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> front(n,0), curr(n,0);
        for(int j=0; j<n; j++) front[j] = triangle[n-1][j];
        for(int i=n-2; i>=0; i--) {
            for(int j=i; j>=0; j--) {
               int down = triangle[i][j] + front[j];
               int diag = triangle[i][j] + front[j+1];
               curr[j] = min(down, diag);
             }
            front = curr;
        }
        return front[0];
    }
