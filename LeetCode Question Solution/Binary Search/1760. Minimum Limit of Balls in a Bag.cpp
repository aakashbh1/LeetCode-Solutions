// 1760. Minimum Limit of Balls in a Bag
class Solution {
public:
    bool f(int m,vector<int>& nums,int maxOperations)
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+= nums[i]/m;
            if(nums[i]%m==0)
            {
                sum--;
            }
          
        }
        return sum<=maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
      int l  = 1,h= *max_element(nums.begin(),nums.end());
        while(l<=h)
        {
            int m = (l+h)/2;
           if(f(m,nums,maxOperations))h = m-1;
            else
                l = m+1;
        }
        return l;
    }
};
