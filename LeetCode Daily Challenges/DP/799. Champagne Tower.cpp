
//Recusion + memoization
class Solution {
public:
    double solve ( int volume , int row , int col, vector<vector<double>>&dp){
        if ( row<0 || col<0 ) return static_cast<double>(0);
        if ( row==0 && col ==0 ) return volume; 
        if (dp[row][col]!=-1) return dp[row][col]; 
        double left = (solve( volume , row-1 , col-1,dp)-1)/2; 
        double right =( solve ( volume , row-1 , col,dp)-1)/2; 
        if ( left <0 )left = 0.00; 
        if ( right <0 ) right = 0.00; 
        return dp[row][col]=left+right<0?0.00000:left+right; 
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp(101,vector<double>(101,-1));  
        return min(1.00,solve(poured, query_row, query_glass,dp));
    }
};

// Dynamic Programming
class Solution {
    public: 
    double champagneTower(int poured, int query_row, int query_glass) {
            double res[query_row+1][query_glass+2];
            memset(res,0,sizeof(res));  
            res[0][0]= poured;
            for (int i = 0; i < query_row; i++) {
                for (int j = 0; j <= query_glass; j++) {
                    double x=max(0.0,(res[i][j]-1.0)/2.0);
                    res[i+1][j]+=x;
                    res[i+1][j+1]+=x;
                }
            }
            return min(1.0,res[query_row][query_glass]);
    }
};
