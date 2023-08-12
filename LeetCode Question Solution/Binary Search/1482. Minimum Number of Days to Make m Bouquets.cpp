class Solution {
public:


    int possible(vector<int> &bloomDay, int mid, int m, int k){
        int cnt=0;
        int number=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid) cnt++;
            else{
                number+=cnt/k;
                cnt=0;
            }
        }

        number+=cnt/k;
        if(number>=m) return 1;
        return 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=m*1ll*k*1ll;
        if(val>bloomDay.size()) return -1;
        int mini=*min_element(bloomDay.begin(),bloomDay.end());
        int maxi=*max_element(bloomDay.begin(),bloomDay.end());
        int low=mini, high=maxi;
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay,mid,m,k)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }

        return ans;
    }
};
