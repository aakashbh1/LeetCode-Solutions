class Solution {
public:

    int solve(int i, int j, string& s1, string& s2, int m, int n, vector<vector<int>> &dp){
      if(i>=m && j>=n){
        return 0;
      }
      if(dp[i][j]!=-1) return dp[i][j];
      if(i>=m) return  dp[i][j]=s2[j]+solve(i,j+1,s1 ,s2,m,n,dp);
      else if(j>=n) return  dp[i][j] = s1[i]+solve(i+1,j,s1,s2,m,n,dp);

      if(s1[i]==s2[j])return dp[i][j]=  solve(i+1,j+1, s1,s2,m,n,dp);
      int delete_s1_i= s1[i]+solve(i+1,j,s1,s2,m,n,dp);
      int delete_s2_j=s2[j]+solve(i,j+1,s1,s2,m,n,dp);


      return dp[i][j]= min(delete_s1_i,delete_s2_j);
    }
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        vector<vector<int>> dp(2001, vector<int>(2001, -1));
        return solve(0,0,s1,s2,m,n,dp);
    }
};
