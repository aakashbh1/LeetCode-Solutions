class Solution {
public:
    int dp[502][502];
    int solve(vector<int>& d, int i , int x , int n){
        if(i == d.size())return 0;
        if(dp[i][n] != -1)return dp[i][n];
        int res = INT_MAX;
        if(i < d.size()-1)res = min(res, d[i+1]-d[i] + solve(d, i+2, x, n));
        res = min(res, x+solve(d, i+1 , x , n+1) );
        if(n>0)res = min(res, solve(d, i+1, x, n-1));
        return dp[i][n] = res;
    }
    int minOperations(string s1, string s2, int x) {
        int n = s1.size();
        vector<int> d;
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i])d.push_back(i);
        }
        
        if(d.size()%2)return -1;
        memset(dp, -1, sizeof dp);
        return solve(d, 0, x , 0);
    }
};
