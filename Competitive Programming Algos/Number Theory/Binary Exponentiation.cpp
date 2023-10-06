// Used to calculate a^n in logn time where brute force takes n time 

// recursive 
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)// power is odd
        return res * res * a;
    else
        return res * res;// power is even
}

// Loop
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)//power is odd 
            res = res * a;// simple multiply it is odd 
        else { // else if power is even 
          a = a * a; // 2 becomes 4 and power divides by half
        b >>= 1; // it means lets say we had 2^8 now a*a makes it 4 and b>>=1 makes b=2 which is equal to 4^2
        }
    }
    return res;
}
