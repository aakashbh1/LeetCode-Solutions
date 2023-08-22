class Solution {
public:
    // time complexity of check func. is O(m+n) 
    // where m and n are size of houses and heaters respectively
    bool check(int mid,vector<int>& houses, vector<int>& heaters){
        int i = 0,j = 0;
        while(j<heaters.size()){
            int leftLimit = heaters[j]-mid;
            int rightLimit = heaters[j]+mid;
            if(i<houses.size() && houses[i]<leftLimit){
                return false;
            }
            while(i<houses.size() && houses[i]>=leftLimit && houses[i]<=rightLimit){
                i++;
            }
            j++;
        }
        if(i!=houses.size()) return false;
        return true;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int l = 0,h = 1e9;
        int ans = -1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(check(mid,houses,heaters)){
                ans = mid;
                h = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};
