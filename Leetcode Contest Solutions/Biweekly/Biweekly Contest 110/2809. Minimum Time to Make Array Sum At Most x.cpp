class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();
        int ss = accumulate(nums1.begin(),nums1.end(),0);
        int ss2 = accumulate(nums2.begin(),nums2.end(),0);
        if (ss <= x){
            return 0;
        }
        
        vector<pair<int, int>> V(n);
        for (int i = 0; i<n ;i++){
            V[i] = make_pair(nums2[i], nums1[i]);
        }
        
        sort(V.begin(), V.end());
        
        const int oo = 2e9;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        
        for (int t = 1; t <= n; t++){
            for (int i = 1; i <= n; i++){
                if (i < t){
                    continue; 
                }
                dp[i][t] = max(dp[i-1][t], V[i-1].first * t + V[i-1].second + dp[i-1][t-1]);
            }
        }
        
        //int ans = oo;
        for (int t = 1; t <= n; t++){
            int tot = ss2 * t + ss;
            //cout << tot << " " << dp[n][t] << "\n";
            if (tot - dp[n][t] <= x){
                return t; 
            }
        }
        return -1;
    }
};
