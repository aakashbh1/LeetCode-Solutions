#define mod 1000000007
class Solution {
    int get_GCD(int a, int b) //function to calculate GCD of two numbers
    {
        if(b == 0) 
         return a;
         
         return get_GCD(b,a % b);
    }
public:
    int nthMagicalNumber(int n, int a, int b) {
       long long  low = 0, high = 1LL * min(a,b) * n, mid;

        int gcd = a > b ? get_GCD(a,b) : get_GCD(b,a);
        long long lcm = (1LL*a*b)/gcd; //simple maths property
        while(low < high)
        {
           mid = low + (high-low)/2;
           long long magicalNum = mid/a + mid/b - mid/lcm;
           if(magicalNum < n) //if there are less than n magical numbers until mid
            low = mid + 1; //then search in right side
           else
            high = mid; //otherwise, search in left side
        }
        return low % mod; //always remember to take mod before returning
    }
};
