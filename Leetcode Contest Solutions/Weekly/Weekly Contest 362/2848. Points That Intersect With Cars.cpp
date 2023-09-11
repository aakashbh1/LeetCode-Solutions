class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            for(int j=nums[i][0];j<=nums[i][1];j++){
                s.insert(j);
            }
        }
        return s.size();
    }
};

Line Sweep Algo

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) 
    {
        int n = nums.size() ; 
        int pref[150] = {0} ;
        int ans = 0 ;  
        for(int i=0; i<n; i++)
        {
            pref[nums[i][0]]++ ;
            pref[nums[i][1] +1 ]-- ;
        }
        for(int i=0; i<110; i++)
        {
            pref[i+1] += pref[i] ;
            if(pref[i]>0) ans++ ;
            cout<<pref[i]<<" ";
        }
        return ans ;
    }

};
