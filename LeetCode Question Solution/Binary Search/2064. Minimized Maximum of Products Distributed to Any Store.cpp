class Solution {
public:
    bool possible(int n, int mid, vector<int> &quantities){
        int count=0;
        for(int i:quantities){
            count+=i/mid;
            if(i%mid) count++;
        }
        return count<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m= quantities.size();
        int low=1, high=*max_element(quantities.begin(),quantities.end()),ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(n,mid,quantities)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }

        return ans;
    }
};
