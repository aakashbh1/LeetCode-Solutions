class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        if(purchaseAmount%10==0) return 100-purchaseAmount;
        
           int roundedAmount1=purchaseAmount/10*10;
           int roundedAmount2=(purchaseAmount/10+1)*10;
        
        int minAmount;
        if(abs(roundedAmount1 - purchaseAmount)>abs(roundedAmount2 - purchaseAmount)) minAmount=roundedAmount2;
        else if(abs(roundedAmount1 - purchaseAmount)==abs(roundedAmount2 - purchaseAmount)){
            minAmount=roundedAmount2;
        }
        else minAmount=roundedAmount1;
        
     return 100-minAmount;
    }
};
