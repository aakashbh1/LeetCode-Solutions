class Solution {
  public:
    int findMin(int A[], int n)
    {   
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
        }
        if(sum%2==0) return 0;
        int count=0;
        for(int i=0;i<n;i++){
            if(A[i]%2==0) count++;
        } 
        if(count==0) return -1;
        int res=INT_MAX;
        
        for(int i=0;i<n;i++){
            if(A[i]%2==0){
                int cnt=0;
                while(A[i]%2==0){
                    A[i]=A[i]/2;
                    cnt++;
                }   
                res=min(res,cnt);
            }
        }
        return res;
    }
};
