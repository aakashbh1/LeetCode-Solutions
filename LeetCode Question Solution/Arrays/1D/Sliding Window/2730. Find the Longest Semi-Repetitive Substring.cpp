
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int pairs_cnt=0;
        char pairs_val;
        
        int i=0, j=0, n=s.length();
        
        int ans=0;
        while(j<n){
            
            if(j>0 && s[j]==s[j-1]) pairs_cnt++;
            
            // keeping track of 1st pair
            if(pairs_cnt == 1 && s[j]==s[j-1]) pairs_val=s[j];
            
            if(pairs_cnt > 1){
                while(i<=j && pairs_cnt > 1){
                    if(s[i]==s[i+1] && s[i]==pairs_val) pairs_cnt--;
                    
                    i++;
                }
                
                pairs_val=s[j]; // updating latest pair value
            }
            
            ans=max(ans,j-i+1);
            j++;
        }
        
        return ans;
    }
};
