
//Implementation
//recursive
int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
//Using the ternary operator in C++, we can write it as a one-liner.

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

//And finally, here is a non-recursive implementation:

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
//stl
int gcd_result = __gcd(a, b);
//lcm
 int lcm_result = (a * b) / __gcd(a, b);
