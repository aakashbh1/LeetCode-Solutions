class Solution
{
    public:
     int mod=1e9+7;
    //Function to count the number of ways in which frog can reach the top.
    long long solve( int n, vector<long long int> &dp){
        if(n==0) return 1;
        if(n<0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        return dp[n]= solve(n-2,dp)%mod+solve(n-1,dp)%mod+solve(n-3,dp)%mod;
    }
      long long solveTab( int n ){
          vector<long long int> dp(n+1,0);
           
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
 
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-2]%mod+dp[i-1]%mod+dp[i-3]%mod;
        }
        
        return dp[n]%mod;
    }
    long long solveSO( int n ){
        
        long  long int curr=0;
        
        long  long int prev1=2;
        long  long int prev2=1;
        long  long int prev3=1;
 
        for(int i=3;i<=n;i++){
            curr=prev1%mod+prev2%mod+prev3%mod;
            prev3=prev2;
            prev2=prev1;
            prev1=curr;
        }
        
        return prev1%mod;
    }
    
    
    
    long long countWays(int n)
    
    {
        if (n == 0 || n == 1) {
            return 1;
        } 
        vector<long long int> dp(n+1, -1);
       
        
        // return solve(n,dp)%mod;
        // return solveTab(n)%mod;
        return solveSO(n)%mod;
         
    }
};
