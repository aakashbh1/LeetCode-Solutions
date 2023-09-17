class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        map<pair<int,int>,int>mp;
        int n=coordinates.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int val=0;val<=k;val++){

                int x=val^coordinates[i][0];
                int y=(k-val)^coordinates[i][1];
                ans+=mp[make_pair(x,y)];
            }
            mp[make_pair(coordinates[i][0],coordinates[i][1])]++;
        }
        return ans;
    }
};
