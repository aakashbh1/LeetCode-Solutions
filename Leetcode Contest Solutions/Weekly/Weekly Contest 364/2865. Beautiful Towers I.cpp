class Solution {
public:
    
    long long sumof(vector<int> m, long long int maxi, long long int maxindex){
        long long int n=m.size();
         long long int last=maxi;
        for(int i=maxindex-1;i>=0;i--){
            if(m[i]>last){
                m[i]=last;
            }
            else if(m[i]<last){
                last=m[i];
            }
        }
        long long int last1=maxi;
        for(int i=maxindex+1;i<n;i++){
            if(m[i]>last1) m[i]=last1;
            else if(m[i]<last1) last1=m[i];
        }
        
        long long int sum= accumulate(m.begin(),m.end(),0LL);
        return sum;
    }
    
    long long maximumSumOfHeights(vector<int>& m) {
        long long int n=m.size();
        long long int maxindex=0;
        long long int maxi=INT_MIN;
        // for(int i=0;i<n;i++){
        //     if(m[i]>maxi){
        //         maxindex=i;
        //         maxi=m[i];
        //     }
        // }
        //  long long int res=INT_MIN;
        // for(int i=0;i<n;i++){
        //     if(m[i]==maxi){
        //         res=max(res,sumof(m,maxi,i));
        //     }
        // }
        long long int res=INT_MIN;
        for(int i=0;i<n;i++){
                res=max(res,sumof(m,m[i],i));
            }
        
        return res;
       
    }
};  
