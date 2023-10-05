----------------------------- This helps to find prime factors of a number n ---------------------------
//Finding Prime factors in o(n)

vector<long long> trial_division(long long n) {
    vector<long long> factorization;

    for (long long d = 2; d  <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }

    return factorization;
}



// in sqrt(n)
vector<long long> trial_division(long long n) {
    vector<long long> factorization;

    for (long long d = 2; d * d <= n; d++) { // at least one prime will be below sqrt(n)
        while (n % d == 0) { // it will always be a prime number to enter this loop as starts from 2 so its multiple are already covered
            factorization.push_back(d); // push that prime number again and again
            n /= d; // how many times like 2^3 so it will push 2 three times in array 
        }
    }

    if (n > 1)
        factorization.push_back(n); // is N is still left that will also be a prime number 

    return factorization;
}
