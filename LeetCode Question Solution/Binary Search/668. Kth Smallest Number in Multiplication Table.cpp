class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int mn = 1, mx = m*n,mid,x=0,ans,i;
        while(mn<=mx){
            mid = (mx-mn)/2+mn;
            x = 0;
            for(i = 1; i <= m; i++){
                x += min(n,mid/i);
            }
            if(x>=k){
                ans = mid;
                mx = mid-1;
            }else{
                mn = mid+1;
            }
        }
        return ans;
    }
};
