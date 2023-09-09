class Solution {
    private:
    void solve(int i,int k,int n,vector<int> &ds,vector<vector<int>> &ans){
        
        if(k==0){
            if(n==0){
                ans.push_back(ds);
            }
            return;
        }
        if(i>9) return ;
        //pick
        if(i<=n){
            ds.push_back(i);
            solve(i+1,k-1,n-i,ds,ans);
            ds.pop_back();
        }
        //nonpick
        solve(i+1,k,n,ds,ans);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1,k,n,ds,ans);
        return ans;

    }
};

/* Template 2 (for loop) 
class Solution {
public:
    void Solve(int arr[], vector<int> temp, vector<vector<int>> &ans, int k, int n, int index)
    {
        if(n==0)
        {
            if(temp.size()==k)
            ans.push_back(temp);
            return ;
        }
        for(int i=index;i<9;i++)
        {
          if(arr[i]<=n)
          {
            temp.push_back(arr[i]);
            Solve(arr, temp, ans, k, n - arr[i], i+1);
            temp.pop_back();
            
          }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        // List of answers to be returned so we can use DFS

         int arr[]={1,2,3,4,5,6,7,8,9};
         vector<int> temp;
         vector<vector<int>> ans;
         Solve(arr, temp, ans, k, n, 0);
       return ans;
    }
};*/
