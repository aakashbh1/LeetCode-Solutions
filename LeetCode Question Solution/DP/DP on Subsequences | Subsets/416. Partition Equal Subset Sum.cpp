//Approach 1 : Recursive

class Solution{
    private: 
    bool solve(int index,int target, vector<int>&arr, int N, int sum){
        if(index>=N) return false ;
        if(sum>target) return false;
        if(sum==target) return true;
        bool take=solve(index+1,target,arr,N,sum+arr[index]);
        bool nottake=solve(index+1,target,arr,N,sum);
        return (take || nottake);
    }
    public:
    bool canPartition(vector<int>& arr) {
        int sum=0;
        int N=arr.size();
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        return solve(0,target,arr,N,0);
    }
};


// Approach 2 : Top Down dp
class Solution{
    private: 
    bool solve(int index,int target, vector<int>&arr, int N, int sum,vector<vector<int>>&dp){
        if(index>=N) return false ;
        if(sum>target) return false;
        if(sum==target) return true;
        if(dp[index][sum]!=-1) return dp[index][sum];
        bool take=solve(index+1,target,arr,N,sum+arr[index],dp);
        bool nottake=solve(index+1,target,arr,N,sum,dp);
        return dp[index][sum]= (take || nottake);
    }
    public:
    bool canPartition(vector<int>& arr) {
        int sum=0;
        int N=arr.size();
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<vector<int>>dp(N+1,vector<int>(target+1,-1));
        return solve(0,target,arr,N,0,dp);
    }
};


// Approach 3 : Bottom Up Dp

class Solution{
    public:
    bool canPartition(vector<int>& arr) {
        int sum=0;
        int N=arr.size();
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<vector<int>>dp(N+1,vector<int>(target+1,0));
        for(int i=0;i<=N;i++){
            dp[i][0]=1;
            
        }
        
        for(int index=N-1;index>=0;index--){
            for(int target=0;target<=sum/2;target++){
                bool take=0;
                if(target-arr[index]>=0 )
                     take=dp[index+1][target-arr[index]];
                
                     bool nottake=dp[index+1][target];
                     dp[index][target]=(take || nottake);        
            }
        }
       return dp[0][sum/2];                         
    }
};
