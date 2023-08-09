class Solution{
public: 
    long long int largestPrimeFactor(int N){
          long long fact = 2;
        
        while(N){
            if(N%fact == 0){
                N = N/fact;
                if(N==1) break;
            }else{
                fact++;
            }
        }
        
        return fact;
    }
};
