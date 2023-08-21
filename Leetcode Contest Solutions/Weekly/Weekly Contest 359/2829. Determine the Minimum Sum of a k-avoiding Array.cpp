class Solution {
public:
    int minimumSum(int n, int k) {
        vector<int> ans(n,0);
        unordered_set<int> s;
        int i=0;
        int x=1;
        while(i<n){
            if(s.count(x)){
                x++;
                 continue;
                
            }
            else{
                ans[i]=x;
                i++;
                s.insert(k-x);
                x++;
            }
            
        }
        
        int res=accumulate(ans.begin(),ans.end(),0);
        return res;
     
    }
};
