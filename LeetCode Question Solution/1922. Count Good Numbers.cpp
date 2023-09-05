class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    static long long binexp(long long a, long long b, int MOD) {
        a %= MOD;
        int res = 1;

        while (b > 0) {
            if (b & 1) {
                res = (res * 1LL * a) % MOD;
            }
            a = (a * 1LL * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    int countGoodNumbers(long long n) {
        long long odds = floor(n / 2.0);
        long long evens = ceil(n / 2.0);
        return (binexp(5, evens, MOD) * 1LL * binexp(4, odds, MOD)) % MOD;
    }
};
