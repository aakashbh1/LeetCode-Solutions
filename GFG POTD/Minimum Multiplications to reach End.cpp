Minimum Multiplications to reach End
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        const int MOD=100000;
        vector<int> visited(MOD,0);
        queue<pair<int,int>> q;
        
        q.push({start,0});
        visited[start]=1;
        
        while(!q.empty()){
            int currentNum=q.front().first;
            int steps=q.front().second;
            q.pop();
            
            if(currentNum==end) return steps;
            
            for(int x:arr){
                int nextNum=(currentNum*x)%MOD;
                
                if(!visited[nextNum]){
                    q.push({nextNum,steps+1});
                    visited[nextNum]=1;
                }
            }
            
        }
        return -1;
    }
};
