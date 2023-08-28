class Solution {
public:
    int trap(vector<int>& arr) {
          int n=arr.size();
 int left[n];
    int right[n];
    
    
    left[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        left[i]=max(left[i-1],arr[i]);
     }
    
    right[n-1]=arr[n-1];
     for(int i = n - 2; i >= 0; i--){
        right[i] = max(right[i+1], arr[i]);
    }
      int ans[n];
    for(int i = 0; i<n; i++){
        ans[i] = min(left[i], right[i]) - arr[i];
    }
    
    long long sum = 0;
    for(int i = 0; i<n; i++){
        sum += ans[i];
    }
    return sum;
    }
};
/*
long long trappingWater(int arr[], int n){
       int left=0, right=n-1;
       long long maxleft=0,maxright=0;
       long long res=0;
       while(left<=right){
           if(arr[left]<=arr[right]){
               if(arr[left]>=maxleft) maxleft=arr[left];
               else res+=maxleft-arr[left];
               left++;
           }
             else{
                if(arr[right] >= maxright) maxright= arr[right];
                else res += maxright - arr[right];
                right--;
            }
        }
        return res;
       }
*/
