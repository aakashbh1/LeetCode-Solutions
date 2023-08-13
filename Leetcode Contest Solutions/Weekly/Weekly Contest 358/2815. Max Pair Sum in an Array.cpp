class Solution {
public:
    
    int getMaxDigit(int num) {
    int maxDigit = -1;  // Initialize to a value lower than any possible digit
    while (num > 0) {
        int digit = num % 10;
        maxDigit = max(maxDigit, digit);
        num /= 10;
    }
    return maxDigit;
}
    int maxSum(vector<int>& arr) {
        int ans=INT_MIN;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                
                
                
                int x1=getMaxDigit(arr[i]);
                
                if(arr[i]==100){
                    x1=1;
                   
                }
                int x2=getMaxDigit(arr[j]);
               
                 if(arr[j]==100){
                    x2=1;
                    
                }
                
                
                if(x1==x2){
                    ans=max(ans,arr[i]+arr[j]);
                }
                
                    
                    
            }
        }
        
        if(ans==INT_MIN) return -1;
        return ans;
    }
};
