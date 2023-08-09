class Solution {
public:
   int MOD = 1e9+7;
    #define ll long long 
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2)
    {
		/*   here we will make a difference array and we calculate the overall
			 diff & we have to minimise the diff as possible as we can         
			 for each element in nums2 find the closest replacable no. in nums1 
			 for that purpose sort the nums 1 array & apply the lower_bound()
			 function for getting the closest no. that we can replace   
         
         eg. num1  ->    1   10  4   4   2   7
             nums2 ->   9   3   5   1   7   4
             diff  ->   8   7   1   3   5   3 => sum : 27(we have to minisize this sum)
         best diff ->   1   1   1   0   0   0  (find using lower_bound() function)
        saved diff ->   7   6   0   2   5   3
    Maximum save   ->   7 
                    
                    sum - maximum save => 27-7 -> 20
        */
        
        int n = nums1.size();
        int res = 0;
        vector<int > diff, temp;
        
        ll actualDiff = 0;
        
        for(int i=0; i<n; i++)
        {
            ll val = abs(nums1[i]-nums2[i]);
            diff.push_back(val);
            actualDiff += (val)%MOD;
        }
        
        // cout << actualDiff << endl;
        
        sort(nums1.begin(), nums1.end());
        
        for(int i=0; i<n; i++)
        {
            int j = lower_bound(nums1.begin(), nums1.end(), nums2[i]) - nums1.begin();
        
            if(j == 0)        // i.e. j is the first index 
            {
                temp.push_back(abs(nums2[i]-nums1[j]));
            }
            
            else if(j == n)      // i.e. j is the last index 
            {
                temp.push_back(abs(nums2[i]-nums1[j-1]));
            }
            
            else 
            {
                int val = min(abs(nums2[i]-nums1[j-1]), abs(nums2[i]-nums1[j]));
                
                temp.push_back(val);
            }
        }
        
        
        for(int i=0; i<n; i++)
        {
            cout << temp[i] << " ";
            
            res = max(res, diff[i] - temp[i]);
        }
        
        cout << res << endl;
        
        int ans = (actualDiff - res + MOD) % MOD;
        
        return ans;
        
    }
};

