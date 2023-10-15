//1e9+7 is the largest prime number for coding uses
(a + b) mod m = ((a mod m) + (b mod m)) mod m //addition
(a - b) mod(m) = (a mod(m) - b mod(m) + m) mod m // subtraction
(a x b) mod m = ((a mod m) x (b mod m)) mod m // mutliplication

(a / b) mod m is not equal to ((a mod m) / (b mod m)) mod m. // not true for division
(a / b) mod m = (a x (inverse of b if exists)) mod m  // its true for division

// modulo inverse 
Let the modular inverse of ‘a mod(m)’ be x.
Then, the modular inverse must satisfy the below equation.
=> (a * x) mod(m) = 1
=> (a * x) % m = 1


// modular exponentian
  // iterative but also could be recursive same as binary exponentiation
  int modular_exponentiation(int a, int b, int MOD = 1e9 + 7){
    int ans = 1;
    a = a % MOD;
    while(b > 0){
        if(b % 2 == 1){
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b / 2;
    }
    return ans;
}
