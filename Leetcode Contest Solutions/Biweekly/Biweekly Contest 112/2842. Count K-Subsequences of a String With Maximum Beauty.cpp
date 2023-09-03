class Solution {
public:
    // Function to return nCr
    long long nCr(long long n,long long r){
        long long ncr = 1, k = 1;
        if (n - r < r)  r = n - r;
        if(r == 0)  return 1;
        while(r) {
            ncr *= n;
            k *= r;
            long long m = __gcd(ncr, k);
            ncr /= m;
            k /= m;

            n--;
            r--;
        }
        return ncr;
    }

    long M = 1e9+7;
    int countKSubsequencesWithMaxBeauty(string &s, int k) {
        // Since k-subsequence have all its characters unique,
        // therefore K can have maximum value 26!
        if(k>26)    return 0;
        
        unordered_map<char,long> mp;
        for(char &ch:s) ++mp[ch];
        // if frequency is less than k return 0
        if(mp.size() < k)   return 0;
        
        vector<pair<long,char>> arr;
        for(auto &it:mp)
            arr.push_back(make_pair(it.second,it.first));

        // Sort according to frequency in decresing order
        sort(arr.begin(),arr.end(),greater<pair<long,char>>());

        long n = 0,r = 0;
        for(long i=0;i<arr.size();++i){
            if(arr[i].first == arr[k-1].first)
                ++n;
            if(i<k && arr[i].first == arr[k-1].first)
                ++r;
        }
        // count ways to select the 'kth' frequency character
        long sum  = nCr(n,r);

        // permutation of k length string with unique characters 
        // will be  product of frequencies of selected character....... Basic Mathematics :)
        for(int i=0;i<k;++i)
            sum = (sum%M * arr[i].first%M)%M;
    
        return (int)sum;
    }
};
