
Time: O(nlog(logn))
Space: O(n)
vector<int> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i*i <= n; i++) { // something like premality test we just go from i=2 to square root of n
        if (isPrime[i]) { // if it is true then mark all the other multiples of i as false
            for (int j = i*i; j <= n; j += i) {  // logic used simple that we started from i*i not 2*i
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}
