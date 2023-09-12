class Solution {
  public:
    int isPerfectNumber(long long n) {
        // code here
        
        long long int sum=1;
         if(n==1){
            return 0;
        }
        
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                sum+=i;
                if(i!=n/i)sum+=n/i;
            }
        }
        
        if (sum==n)
        return 1;
        else return 0;
    }
};
