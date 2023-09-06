978. Longest Turbulent Subarray
class Solution {
public:
    bool flag;
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size(),i=0,j=1,ans=1;                                                                            
        while(j<n){                   // > --> taking it as true
            if(i==j-1)                // < --> taking it as false
                flag = (arr[j] < arr[j-1])? true : false;
            if(arr[j] == arr[j-1]){
                i=j++;
                continue;
            }
            bool ch=false;
            if(arr[j] < arr[j-1])
                ch=true;
            if(ch == flag)
                i=j-1;
            else
                flag=ch;
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
    
