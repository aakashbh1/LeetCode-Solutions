class Solution {
public:
    int candy(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n,1) , right(n,1);
        for(int i=1;i<n;i++)
        {
            if(arr[i]>arr[i-1])
            {
                left[i]=left[i-1]+1;
            }
        }
        for(int j=n-2;j>=0;j--)
        {
            if(arr[j]>arr[j+1])
            right[j] = right[j+1]+1;
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=max(left[i],right[i]);
        }
        return sum;
    }
};
