class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int,int> mp;
        for(int i=0;i<intervals.size();i++){
            mp[intervals[i][0]]=i;
        }
        vector<int> ans;
        for(int i=0;i<intervals.size();i++){
            auto it=mp.lower_bound(intervals[i][1]);
            // to check start of jth element >= end of ith element used lower_bound
            if(it!=mp.end()){  
                int key=it->first; // start of jth element
                int value=it->second; // index of jth pair element
                ans.push_back(value);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
