class Solution {
public:

int firstOccurence(vector<int>& arr, int x){
    int s=0;
    int e=arr.size()-1;
    int ans=-1;

    while(s<=e)
    {
        int mid=s+(e-s)/2;

        if(arr[mid]==x)
        {
            ans=mid;
            e=mid-1;
        }

        else if(arr[mid]>x)
        {
            e=mid-1;
        }

        else
        s=mid+1;
    }

    return ans;
}

int lastOccurence(vector<int>& arr, int x){
    int s=0;
    int e=arr.size()-1;
    int ans=-1;

    while(s<=e)
    {
        int mid=s+(e-s)/2;

        if(arr[mid]==x)
        {
            ans=mid;
            s=mid+1;
        }

        else if(arr[mid]>x)
        {
            e=mid-1;
        }

        else
        s=mid+1;
    }

    return ans;
}
 
    vector<int> searchRange(vector<int>& nums, int x) {
        vector<int> ans;

        int first=firstOccurence(nums,x);
        int last=lastOccurence(nums,x);

        ans.push_back(first);
        ans.push_back(last);

        return ans;
    }
};
