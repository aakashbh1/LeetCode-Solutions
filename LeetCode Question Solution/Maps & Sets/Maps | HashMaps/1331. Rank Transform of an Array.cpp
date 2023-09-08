class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans=arr;
        if (arr.size()==0) return {};
        sort(ans.begin(),ans.end());
        unordered_map<int,int> mp;
        mp[ans[0]]=1;
        int count=1;
        for(int i=1;i<ans.size();i++){
            if(ans[i]>ans[i-1]) mp[ans[i]]=++count;
        }

        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }

        return arr;
    }
};
