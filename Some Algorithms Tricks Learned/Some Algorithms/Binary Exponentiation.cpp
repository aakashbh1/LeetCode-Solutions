// Binary exponentiation is a technique used to efficiently calculate the power of a number. 
// It's especially useful when working with large numbers or when you need to calculate powers modulo a number. 
// Here's a C++ implementation of binary exponentiation:

// In this code, the binaryExponentiation function takes two parameters, a (the base) and b (the exponent),
// and returns a^b efficiently using binary exponentiation.

// Here's how it works:

// Initialize result to 1.
// Iterate while b is greater than 0.
// If the least significant bit of b is 1 (i.e., b % 2 == 1), multiply result by a.
// Square a (i.e., a = a * a) to prepare for the next iteration.
// Right-shift b by 1 (i.e., b /= 2) to check the next bit.
// Repeat steps 3-5 until b becomes 0.
// Return the result.
// This algorithm reduces the number of multiplications required to calculate a^b, making it much faster for large exponents.


// Function to calculate a^b using binary exponentiation
long long binaryExponentiation(long long a, long long b) {
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = result * a;
            b--;
        }
        a = a * a;
        b /= 2;
    }
    return result;
}







