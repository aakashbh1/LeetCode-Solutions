//BRUTE FORCE 
int numberOfBeautifulIntegers(int low, int high, int k) {
       int count = 0;

        for (int num = low; num <= high; num++) {
            int temp = num;
            int oddCount = 0, evenCount = 0;

            while (temp > 0) {
                int digit = temp % 10;
                if (digit % 2 == 0) {
                    evenCount++;
                } else {
                    oddCount++;
                }
                temp /= 10;
            }

            if (oddCount == evenCount && num % k == 0) {
                count++;
            }
        }

        return count; 
    }

// ONE MORE 
public class Solution {
    public int NumberOfBeautifulIntegers(int low, int high, int k) {
        low = ((low-1)/k + 1) * k;
        var count = 0;
        while (low <= high)
        {
            count += Check(low);
            low += k;

            if (low >= 100000000) return count;
        }
        
        return count;
    }

    int Check(int low) {
        var even = 0;
        var odd = 0;

        while (low > 0)
        {
            if (low % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }

            low /= 10;
        }

        return even == odd ? 1 : 0;
    }
}

// OPTIMISED DIGIT DP 

class Solution {
public:
    
    int dp[11][21][50][2][2];
    
    int solve(string& num, int n, int diff, int sum, int k, bool leading, bool tight){
        
        if(n == 0){
            if(diff==0 && sum == k) return 1;
            else return 0;
        }
        
        if(dp[n][10+diff][sum][leading][tight] != -1) return dp[n][10+diff][sum][leading][tight];
        
        int ans = 0;
        int ub = tight ? num[num.size()-n]-'0' : 9;
        
        for(int dig = 0; dig<=ub; dig++){
            if(dig == 0 && leading == 1){
                ans += solve(num, n-1, diff, (sum%k)+k, k, 1, 0);
            }
            else{
                int val = 1;
                for(int i=0; i<n-1; i++){
                    val *= 10;
                }
                if(dig%2){
                    ans += solve(num, n-1, diff+1, ((sum+(dig*val))%k)+k, k, 0, (tight&(ub==dig)));
                }
                else{
                    ans += solve(num, n-1, diff-1, ((sum+(dig*val))%k)+k, k, 0, (tight&(ub==dig)));
                }
            }
        }
        return dp[n][10+diff][sum][leading][tight] = ans;
    }
    
    int numberOfBeautifulIntegers(int low, int high, int k) {
        
        string l = to_string(low-1);
        string r = to_string(high);
        
        memset(dp, -1, sizeof(dp));
        int a = solve(l, l.size(), 0, 0, k, 1, 1);
        memset(dp, -1, sizeof(dp));
        int b = solve(r, r.size(), 0, 0, k, 1, 1);
        
        return b-a;
        
    }
};
