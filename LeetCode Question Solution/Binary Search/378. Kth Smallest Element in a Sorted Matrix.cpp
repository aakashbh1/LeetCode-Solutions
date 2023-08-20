#define ll long long 
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        
        int n = mat.size() ;
        auto check=[&](int mid){
            ll cnt = 0 ;
            for(int i = 0 ;i < n ; i++){
                cnt+=(upper_bound(mat[i].begin(),mat[i].end(), mid)-mat[i].begin());
            }
            return cnt>=k;
        };
        ll lo = -1e9+10 , hi =1e9+10, ans = 0 ;

        while(lo<=hi){
            ll  mid = (lo+hi)/2;
            if(check(mid)){
                ans = mid ; 
                hi = mid - 1;
            }else{
                lo = mid +1 ;
            }
        }
        return ans ;

    }
};
// BRUTE FORCE 
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int z) {
         int n = matrix.size(), m = matrix[0].size();
        int a[n*m], k=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                a[k] = matrix[i][j];
                k++;
            }
        }
        sort(a, a+(n*m));
        return a[z-1];
    }
};
