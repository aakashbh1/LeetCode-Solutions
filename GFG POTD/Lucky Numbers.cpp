// Lucky Numbers
class Solution{
public:
    bool isL(int n, int i)
    {
        if(n<i) return true;
        if(n%i==0)
        {
            return false;
        }
        return isL(n-n/i,i+1);
    }
    bool isLucky(int n) {
        return isL(n,2);
    }
};
/*
bool isLucky(int n) {

       for(int i=2;i<=n;i++){

           if(n%i==0)return false;

           n = n - n/i; 

       }

        return true;

    }
*/
