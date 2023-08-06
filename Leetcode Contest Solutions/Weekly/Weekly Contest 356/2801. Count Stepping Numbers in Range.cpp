typedef long long   ll;
ll mod = 1000000007;

class Solution {
public:
    ll dp[101][2][2][11];

    ll helper(ll pos, ll tight, ll isZero, ll prevDigit, string &s) {
        if (pos == (ll) s.size()) {
            if (isZero) return 0;
            return 1;
        }

        if (dp[pos][tight][isZero][prevDigit + 1] != -1) return dp[pos][tight][isZero][prevDigit + 1];

        ll res = 0;
        ll limit;

        if (tight) limit = (s[pos] - '0');
        else limit = 9;

        for (ll curDigit = 0; curDigit <= limit; curDigit++) {

            ll newTight = tight;
            if (tight && curDigit < limit) newTight = 0;

            ll willBeZero = isZero;
            if (isZero && curDigit > 0) willBeZero = 0;

            if (isZero) {
                res += helper(pos + 1, newTight, willBeZero, curDigit, s);
                res %= mod;
            } else {
                if (abs(curDigit - prevDigit) == 1) {
                    res += helper(pos + 1, newTight, willBeZero, curDigit, s);
                    res %= mod;
                }
            }
        }

        dp[pos][tight][isZero][prevDigit + 1] = res;
        return res;
    }
    
    int countSteppingNumbers(string low, string high) {
        
        memset(dp, -1, sizeof(dp));
        ll l = helper(0, 1, 1, -1, low);
        
        memset(dp, -1, sizeof(dp));
        ll r = helper(0, 1, 1, -1, high);
        
        ll res = r - l;
        res %= mod;
        res += mod;
        res %= mod;
        
        ll add = true;
        for (ll i = 1; i < (ll) low.size(); i++)
            if (abs(low[i] - low[i - 1]) != 1) add = false;
        if (add) res++;
        
        res %= mod;
        return res;
    }
};

//OR 
class Solution {
public:
    int mod = 1e9+7;
    int dp[11][105];

    // Recursive function for counting where prev is the previous digit and n is the size of the number we want to form.
    int solve(int prev,int n){
        if(n==0) return 1;
        if(dp[prev][n]!=-1) return dp[prev][n];
        int a=0,b=0;
        if(prev+1<=9) a = solve(prev+1,n-1);
        if(prev-1>=0) b = solve(prev-1,n-1);
        return dp[prev][n] = (a%mod + b%mod)%mod;
    }
    int countSteppingNumbers(string low, string high) {
        int a = low.size();
        int b = high.size();
        memset(dp,-1,sizeof(dp));

        int ans = 0;

        // 1st Part
        for(int x=a+1;x<=b;x++){
            for(int y=1;y<=9;y++){
                ans = (ans%mod) + (solve(y,x-1));
            }
        }
        int dif = 0;

        //2nd Part
        //Count possible numbers of size(low) and greater than low and adding to the answer.
        int x=0;
        for(;x<a;x++){
            int dig = low[x]-'0';
            for(int y=dig+1;y<=9;y++){
                if(x>0 && abs(y-(low[x-1]-'0'))!=1) continue;
                ans = (ans%mod) + (solve(y,a-x-1)%mod);
            }
            if(x>0 && abs(low[x]-low[x-1])!=1) break;
        }
        if(x==a) ans++;

        //3rd Part
        //Count possible numbers of size(high) and greater than high and subtracting from the answer.
        x=0;
        for(;x<b;x++){
            int dig = high[x]-'0';
            for(int y=dig+1;y<=9;y++){
                if(x>0 && abs(y-(high[x-1]-'0'))!=1) continue;
                dif = (dif%mod) + (solve(y,b-x-1)%mod);
            }
            if(x>0 && abs(high[x]-high[x-1])!=1) break;
        }

        int res = ((ans%mod)-(dif%mod));
        return res<0?res+mod:res;
    }
};
