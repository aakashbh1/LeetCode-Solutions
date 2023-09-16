So in this module we will learn how to write 1D dp  
This dp involves just one changing argument so it is known as 1 dimension DP  
Dp is just a extra storage where you store you variables thats it  
STEPS:  

1. Recursion : To write any dp problem you will need a recursive relation which you will optimise.
               This approach will be take a lot of time and space so we will optimise it  
               -> find the changing variables (index)// write in form of index and variables to pass arguments  
               -> Write base case  
               -> Do some task if required(optional)  
               -> Write recusrive relation for further calls  
               -> Return count/max/min whatever asked   

              
Code Example: 

            int solve(int n, int i) {// indexes and changing arguments 
            if(i == n) // base cases
                return 1;
            if(i > n) // corner cases
                return 0;
            return solve(n, i+1) + solve(n, i+2); // recursive relation and return whatever asked  
           }   

2. Memoization(Top-Down): This will have a dp vector initialised with -1, this will store previously calculated results.  
                         Appraoch: ->initialse a vector of size and value=-1  
                                   ->pass as an arguments wherever function call are made  
                                   -> check if dp[n]!=-1 if not then return the value   
                                   -> at last store the returning value in dp[n]
   Here extra space of dp will be included but yes the time complextiy will reduce a lot
   you will either go from 0->n or n->0 it completely depend on you no problem but just remember what you did

     Code Example:

       int solve(int n, int i, vector<int>& dp) { // passsed as argument
        if(i == n)
            return 1;
        if(i > n)
            return 0;
        
        if(dp[i] != -1) // checks if already there 
            return dp[i];

        return dp[i] = solve(n, i+1, dp) + solve(n, i+2, dp);
       }

 3. Tabulation(Bottom up): This will have a dp vector initialised with 0, this will store previously calculated results but this will remove recusrive calls
                            Tabulation removes recusrsion and uses for loop to solve rather than recusrion
                           It is bottom up which means say you went from n->0 in memoization/ top down now the for loop will run from 0>n and return dp[n]   
                         Appraoch: ->initialse a vector of size and value=0  
                                   ->all the bases cases will change to dp vector indexes 
                                   -> run a for loop opposite to what you did in top down    
                                   -> change the fucntion calls to dp[n-1] or dp[i-3] or something as no fucntion calls are made just a for loop is there

    
   Code Example:

     int climbStairs(int n) {
          vector<int> dp(n+2, 0);// initialization 
  
          // from base case
          dp[n] = 1; // base case handling 
  
          for(int i = n-1; i >= 0; i--) { // in top down we went from 0->n so now its n->0 and we return where loop end i.e 0
              dp[i] = dp[i+1] + dp[i+2]; // n+2 --> will solve this issue when i = n-1 => i+2 = n+1 --> out of bound
          } // solve recursive fucntion call has been changed to dp[]s 
  
          return dp[0];// loop ends at 0 as n--> 0
      }


   4. Space Optimization: so in bottom up we saw dp vector was used but in recusrive calls only last 2 or 3 states were required to get the
                          current value then why to keep track of whole dp so space optimization reduces the dp array which memoization started firstly    
                         Appraoch: ->initialise curr and prev1 and prev2 or more according to situation 
                                   ->change the dp indexes base cases to values of prev1,prev2... accordingly 
                                   -> run a for loop opposite to what you did in top down    
                                   -> change the fucntion calls to curr=prev1+prev2  or something as no fucntion calls are made just a for loop is there
                                   -> Now before exiting loop change the variable values to upadeted ones so that next iteration can use them freshly

    
   Code Example:

       int climbStairs(int n) {
        // from base case
        int next1 = 1; // prev1
        int next2 = 0; // prev2 
        int curr = 0;
        // also prev1 prev2 handles the base case easily

        for(int i = n-1; i >= 0; i--) {
            curr = next1 + next2;// curr is upadated
            next2 = next1; // next2 becomes next 1
            next1 = curr; // next1 becomes curr it means for next iteration this curr will act as next1
        }

        return next1; // also can return curr or next1
    }
