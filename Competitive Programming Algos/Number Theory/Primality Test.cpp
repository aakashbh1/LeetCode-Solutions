Lets say we need to find all the divisors to n then what we will do to solve this we   
so we will write something like this 

            for(int i=1;i<=n;i++){
                if(n%i==0) cout<<"i";
            }
we ran a loop from i=1 to i=n to find all the numbers that are divisible by n

But one method is very simple and works in O(sqrt(n))
lets take 12 its divisors are 
1 2 3 4 6 12 
which can be divided into pairs as (1,12) (3,4) (2,6)
so we can see that if we get 2 we can find 6 and if we get 3 we can get 4
so the simple logic is run i from i=1 to i*i<=n 
this will give us all 1,2,3 through which rest 4,6,12 can be found out easily
So this is primality test.
Code:
  
      bool isPrime(int x) {
          for (int d = 2; d * d <= x; d++) {// example of code d*d<=x
              if (x % d == 0)
                  return false;
          }
          return x >= 2;
      }  
