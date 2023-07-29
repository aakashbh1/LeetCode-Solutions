//Recursion
class Solution {
public:
    int find(int& m, int& n, int i, int j){
        if(i==m || j==n) return 0;  // Out of bounds
        if(i==m-1 && j==n-1) return 1;
        return find(m, n, i+1, j) + find(m, n, i, j+1);
    }
    int uniquePaths(int m, int n) {
        return find(m, n, 0, 0);
    }
};

//Memoization 
class Solution {
public:
    int find(vector<vector<int>>& dp, int& m, int& n, int i, int j){
        if(i==m || j==n) return 0;  // Out of bounds
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j] = find(dp, m, n, i+1, j) + find(dp, m, n, i, j+1);
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return find(dp, m, n, 0, 0);
    }
};

//Tabulation (Bottom Up)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        if(m==1 && n==1) return 1;
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j]=0;
                dp[i][j] += dp[i+1][j];
                dp[i][j] += dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};

//Space Optimization 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(2, vector<int>(n, 1));
        int f=(m-2)&1;
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[f][j] = dp[!f][j] + dp[f][j+1];
            }
            f=!f;
        }
        return dp[0][0];
    }
};
