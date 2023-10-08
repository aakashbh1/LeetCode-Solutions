class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end());
        priority_queue<int> pq(tasks.begin(),tasks.end());
        int n=processorTime.size();
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int res=INT_MIN;
            int x=4;
            while(x){
                int temp=pq.top();
                pq.pop();
                res=max(res,processorTime[i]+temp);
                x--;
            }
            
           ans=max(ans,res); 
        }
        
        return ans;
    }
};
