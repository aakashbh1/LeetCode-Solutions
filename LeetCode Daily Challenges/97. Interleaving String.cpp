 bool recursion(string& s1,string& s2, string& s3, int i,int j,int k)
    {
        //if all three indexes of three strings are at last position that means we have achied third string by interleaving s1 and s2. 
        if(i>=s1.length() && j>=s2.length() && k>=s3.length())  
            return true;
        //if this condition is not fulfilled then the default value of flag will be returned(false).

        bool flag=false;

        if(i<s1.length() && s1[i]==s3[k])
            flag = flag || recursion(s1,s2,s3,i+1,j,k+1);

        if(j<s2.length() && s2[j]==s3[k])
            flag = flag || recursion(s1,s2,s3,i,j+1,k+1);
        
        return flag;
    }

    bool TopDown(string& s1,string& s2, string& s3, int i,int j,int k,vector<vector<vector<int>>>& dp) //i is going from 0 to s1.size() & j is going from 0 to s2.size() & k is going from 0 to s3.size()
    {
         
        if(i>=s1.length() && j>=s2.length() && k>=s3.length())  
            return true;

        if(dp[i][j][k]!=-1)
            return dp[i][j][k];

        bool flag=false;

        if(i<s1.length() && s1[i]==s3[k])
            flag = flag || TopDown(s1,s2,s3,i+1,j,k+1,dp);

        if(j<s2.length() && s2[j]==s3[k])
            flag = flag || TopDown(s1,s2,s3,i,j+1,k+1,dp);
        
        dp[i][j][k]=flag;
        return dp[i][j][k];
    }

    bool BottomUp(string s1, string s2, string s3)
    {
        vector<vector<vector<bool>>> dp(s1.length()+1,vector<vector<bool>>(s2.length()+1,vector<bool>(s3.length()+1,false)));
        //we have initialized it with false as in many cases it is returning false.(for many cells)

        dp[s1.size()][s2.size()][s3.size()]=true;

        //we have to start the loop from s1/s2/s3.size() as if one is string is completed but the remaining two are stil traversing.so to get the answer in this scenario we are running the loop.only in base case it will continue. 

        for(int i=s1.size();i>=0;i--)
        {
            for(int j=s2.size();j>=0;j--)
            {
                for(int k=s3.size();k>=0;k--)
                {
                    if(i>=s1.length() && j>=s2.length() && k>=s3.length())  
                        continue;
                        
                    bool flag=false;

                    if(i<s1.length() && s1[i]==s3[k])
                        flag = flag || dp[i+1][j][k+1];

                    if(j<s2.length() && s2[j]==s3[k])
                        flag = flag || dp[i][j+1][k+1];
                    
                    dp[i][j][k]=flag;
                }
            }
        }
        return dp[0][0][0];
    }

    
    bool isInterleave(string s1, string s2, string s3) 
    {

        int i=0,j=0,k=0;
        //return recursion(s1,s2,s3,i,j,k);
        
        // vector<vector<vector<int>>> dp(s1.length()+1,vector<vector<int>>(s2.length()+1,vector<int>(s3.length()+1,-1)));
        // return TopDown(s1,s2,s3,i,j,k,dp);

        return BottomUp(s1,s2,s3);
    }
