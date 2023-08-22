class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int,int> mp;
        int maxi=INT_MIN;
        sort(items.begin(),items.end());
        int n=items.size();
        int m=queries.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,items[i][1]);
            mp[items[i][0]]=maxi;
        }

        for(int i=0;i<m;i++){
           auto upper = mp.upper_bound(queries[i]);
           if(upper==mp.begin()) queries[i]=0;
           else queries[i]=(--upper)->second;
        }

        return queries;
    }
};
