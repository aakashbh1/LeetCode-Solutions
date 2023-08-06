class Solution{
    public:
    
     int maxi=0;
    int help(string& s1,string& s2,int i,int j,vector<vector<int>>& memo)
    {
        //base case
        if(i<0 or j<0)
        return 0;
        
        //memo check - is ans already calculated
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        //recursive calls
        //small calculation
        
        int take=0;
        if(s1[i]==s2[j])
        {
            take=1+help(s1,s2,i-1,j-1,memo);
            maxi=max(take,maxi);
        }
        
        help(s1,s2,i-1,j,memo);
        help(s1,s2,i,j-1,memo);
        
        memo[i][j]=take;
        return take;
    }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>> memo(n+1,vector<int>(m+1,-1));
        int a=help(S1,S2,n-1,m-1,memo);
        return maxi;
    }

};
