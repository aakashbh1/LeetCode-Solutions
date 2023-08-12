
    bool check(vector<int>& stalls,int mindiff,int k){

        int cnt=1;
        int prev=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if((stalls[i]-prev)>=mindiff)
            {
                cnt++;
                prev= stalls[i];
            }

        }
        return cnt>=k;

    }
    int maxDistance(vector<int>& stalls, int m) {
        int n= stalls.size();
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high= stalls[n-1]-stalls[0];
        int ans=INT_MIN;
        while(low<=high){
            int mid=(low+high)>>1;
            if(check(stalls,mid,m)){
                ans= mid;
                low= mid+1;
            }
            else
            high= mid-1;

        }

        return ans;
    }
