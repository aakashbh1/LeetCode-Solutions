//Application Below
class Solution
{
    public:
    //Function to find the nth catalan number.
// Recursive + Dp
    int mod = 1e9+7;
  int solve(int n,vector<long long > &dp){
      if(n<=1) return 1;
      if(dp[n]!=-1) return dp[n];
      long long int ans=0;
      
      for(int i=0;i<n;i++){
          ans=(ans+solve(i,dp)*solve(n-i-1,dp))%mod;
          
      }
      
      return dp[n]=ans;
  }
      //Tabulation
  int solveTab(int n){
      vector<long long > dp(n+1,1);
      
        for(int i=2;i<=n;i++){
          
          long long int ans=0;
            for(int j=0;j<i;j++){
              ans=(ans+dp[j]*dp[i-j-1])%mod;
         }
           dp[i] = ans;
          
      }
      
      return dp[n];
  }
  int findCatalan(int n) {
      vector<long long > dp(n+1,-1);
    //  return solve(n,dp);
    return solveTab(n);
    }
};


Parentheses Expressions: The nth Catalan number represents the number of different ways to arrange parentheses in a valid expression.
This is crucial in problems related to well-formed parentheses, like checking the validity of expressions and generating all valid combinations.

Binary Search Trees (BSTs): The nth Catalan number gives the number of unique BSTs that can be formed with n nodes. 
This concept is applied in optimizing search operations and data retrieval.

Dyck Paths: Catalan numbers also count the number of paths that stay above the diagonal in a grid from (0,0) to (n,n), but do not cross it.
These paths have steps (1,1) or (1,-1) which are often referred to as "up" and "down" steps.

Triangulations of a Polygon: The nth Catalan number also represents the number of ways to triangulate a polygon with n+2 sides. 
This is essential in various geometric algorithms.

Non-crossing Partitions: In combinatorics, Catalan numbers count the number of non-crossing partitions of a set of n elements. 
This concept is important in solving problems related to discrete structures.

Expression Trees: Catalan numbers are used in the calculation of the number of different ways to construct a full binary tree with n+1 leaves. 
This is applicable in compiler design and expression evaluation.

Balanced Ternary Strings: Catalan numbers count the number of balanced ternary strings of length 2n, 
where a balanced ternary string is one in which the number of 1s is equal to the number of -1s.

Counting Paths in a Grid: In a grid with n rows and n columns, the nth Catalan number gives the number of paths 
from the top-left corner to the bottom-right corner that do not cross the diagonal.
