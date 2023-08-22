       	//Memoization
        int Choices(string s, int index, vector<int> &dp)
        {
            if (index == s.size())
               	//Only 1 char is left as we have reached the end so no choice
               	//other than taking it
                return 1;
            if (dp[index] != -1)
               	//If sub-problem is solved earlier
                return dp[index];
            int res = 0;
            if (s[index] != '0')
                res += Choices(s, index + 1, dp);
           	//Solving for single character
            if (index + 1 < s.size() && (s[index] == '1' || s[index] == '2' && s[index + 1] <= '6'))
               	//Solving for double character
                res += Choices(s, index + 2, dp);
            return dp[index] = res;
        }
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return Choices(s, 0, dp);
    }

//=====================================================================================================
   	//TABULATION
   	int numDecodings(string s)
   	{
   	    int n = s.size();
   	    vector<int> dp(n + 1, 0);
   	    dp[0] = 1;
   	    dp[1] = s[0] != '0' ? 1 : 0;	// Initialize dp[1] based on the first character

   	    for (int index = 2; index <= n; index++)
   	    {
   	       	// Single-digit case
   	        if (s[index - 1] != '0')
   	            dp[index] += dp[index - 1];

   	       	// Two-digit case
   	        int twoDigitNum = stoi(s.substr(index - 2, 2));
   	        if (twoDigitNum >= 10 && twoDigitNum <= 26)
   	            dp[index] += dp[index - 2];
   	    }

   	    return dp[n];
   	}

//=====================================================================================================

   	//SPACE-OPTIMIZED TABULATION
    int numDecodings(string s)
    {
        int n = s.size();

        int two_index_back = 1;
       	//dp[0]=0(dp val 2 index back from index)
        int one_index_back = s[0] != '0' ? 1 : 0;
       	//dp[1]=1(dp val 1 index back from index)
        int curr_index = 0;

        for (int index = 2; index <= n; index++)
        {
           	// Single-digit case
            if (s[index - 1] != '0')
                curr_index += one_index_back;

           	// Two-digit case
            int twoDigitNum = stoi(s.substr(index - 2, 2));
            if (twoDigitNum >= 10 && twoDigitNum <= 26)
                curr_index += two_index_back;

           	//Swapping
            two_index_back = one_index_back;
            one_index_back = curr_index;
            curr_index = 0;
        }

        return one_index_back;
    }
};
