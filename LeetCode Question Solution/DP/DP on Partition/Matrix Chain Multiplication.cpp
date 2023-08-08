class Solution{
public:
int solve(int i , int j , int arr[],vector<vector<int>>&dp){
    if(i == j)return 0;
    int mini = 1e9;
    if(dp[i][j]!= -1)return dp[i][j];
    for(int k =i;k<j; k++){
        int step = arr[i-1]*arr[j]*arr[k] +solve(i, k, arr,dp)+ solve(k+1, j, arr,dp);
      if(step<mini)mini = step;
    }
    return dp[i][j] = mini;
    
}
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(N+1, vector<int>(N+1, -1));
        return solve(1, N-1, arr,dp);
        // code here
    }
};
