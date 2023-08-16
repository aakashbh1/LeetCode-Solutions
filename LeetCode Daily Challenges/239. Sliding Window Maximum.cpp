Code
class Solution {
    using int2=pair<int, int>; //(nums[i], i)
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int2> pq;

        vector<int> ans(n-k+1);
        for (int i=0; i<k; i++)
            pq.push({nums[i], i});
        
        ans[0]=pq.top().first;
        for(int i=k; i<n; i++){
            while(!pq.empty() && pq.top().second<=(i-k))
                pq.pop(); //Pop up element not in the window
            pq.push({nums[i], i});
            ans[i-k+1]=pq.top().first;//Max element for this window
        }
        return ans;
    }
};
Code using Deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> max_idx;//Double-ended queue storing index for max
        vector<int> ans(n-k+1);

        for(int i=0; i<n; i++){
            while(!max_idx.empty() && nums[i]>=nums[max_idx.back()]) 
                max_idx.pop_back();// pop back the indexes for smaller ones
            max_idx.push_back(i);  // push back the index for larger one

            if (max_idx.front()==i-k) // index=i-k should not in the window
                max_idx.pop_front(); 
            if (i>=k-1)
                ans[i-k+1]=nums[max_idx.front()]; //Max element for this window
        }
        return ans;
    }
};
