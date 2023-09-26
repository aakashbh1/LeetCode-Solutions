class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        int low,high,sum=0;
        set<vector<int>> ans;
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                low=j+1;
                high=n-1;
                
                while(low<high)
                {
                    vector<int> v;
                    sum=arr[i]+arr[j]+arr[low]+arr[high];
                    
                    if(sum==k)
                    {
                        v.push_back(arr[i]);
                        v.push_back(arr[j]);
                        v.push_back(arr[low]);
                        v.push_back(arr[high]);
                        sort(v.begin(),v.end());
                        ans.insert(v);
                    }
                    if(sum<k)low++;
                    else high--;
                }
            }
        }
        
        vector<vector<int>> res;
        for(auto it:ans)
        {
             res.push_back(it);
        }
        
        return res;
        
    }
};
