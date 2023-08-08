->Recursion
    
//tc= o(2^n)
//sc=o(n)

class Solution {
public:
    
    int f(int ind,int prev,vector<int>&nums,int n)
    {
        if(ind==n) return 0;
        int len= 0 + f(ind+1,prev,nums,n);

        if(prev==-1 || nums[ind]>nums[prev])
        len=max(len,1+f(ind+1,ind,nums,n));

        return len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return f(0,-1,nums,n);
    }
};

---------------------------------------------------------------------
        
-Memoization

class Solution {
public:

    int ff(int ind,int prev,vector<int>&nums,int n,vector<vector<int>>&dp)
    {
        if(ind==n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int len= 0 + ff(ind+1,prev,nums,n,dp);

        if(prev==-1 || nums[ind]>nums[prev])
        len=max(len,1+ff(ind+1,ind,nums,n,dp));

        return dp[ind][prev+1]=len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return ff(0,-1,nums,n,dp);
    }
};

----------------------------------------------------------------------

->Tabulation

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prev=ind-1;prev>=-1;prev--)
            {
                int len=0+dp[ind+1][prev+1];

                if(prev==-1 || nums[ind]>nums[prev])
                len=max(len,1+dp[ind+1][ind+1]);

                dp[ind][prev+1]=len;
            }
        }
        return dp[0][-1+1];
    }
};

---------------------------------------------------------------------

->Space Optimized

//tc=o(n^2)
//sc=o(n)*2

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>next(n+1,0),curr(n+1,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prev=ind-1;prev>=-1;prev--)
            {
                int len=0+next[prev+1];

                if(prev==-1 || nums[ind]>nums[prev])
                len=max(len,1+next[ind+1]);

                curr[prev+1]=len;
            }
            next=curr;
        }
        return next[-1+1];
    }
};

---------------------------------------------------------------------

->More Optimized

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int maxi=0;
        for(int ind=0;ind<n;ind++)
        {
            for(int prev=0;prev<ind;prev++)
            {
                if(nums[prev]<nums[ind])
                dp[ind]=max(dp[ind],1+dp[prev]);
            }
            maxi=max(maxi,dp[ind]);
        }
        return maxi;
    }
};

----------------------------------------------------------------------

->Binary Search Method

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        temp.push_back(nums[0]);
        int len=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>temp.back())
            {
                temp.push_back(nums[i]);
                len++;
            }
            else
            {
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return len;
    }
};
