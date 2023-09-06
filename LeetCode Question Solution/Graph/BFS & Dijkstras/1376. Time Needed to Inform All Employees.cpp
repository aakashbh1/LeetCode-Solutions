// 1376. Time Needed to Inform All Employees
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        //Creating adjacency list 
        vector<int>adj[n];

        for(int i=0;i<manager.size();i++){
            if(manager[i] != -1){
                //as per the question manager[i] is the manager of any index i
                adj[manager[i]].push_back(i);
            }
        }

        //here keeping headId in queue as it is boss of company so everthing will start from it
        queue<pair<int,int>>q;
        q.push({headID,0});

        vector<bool>vis(n,false);
        vis[headID]=true;

        int time=0,ans=0;
        while(!q.empty()){
            //manger will be our new manager and it will take infromTime[manger]
            //to inform its employee under him
            int manager=q.front().first;
            time=q.front().second;
            //taking maximum as our answer
            ans=max(ans,time);
            q.pop();
            //Going through all neighbours
            for(auto &neigh:adj[manager]){
                if(vis[neigh] == false){
                    vis[neigh]=true;
                    //Updating time with informTime[manager]
                    q.push({neigh,time+informTime[manager]});
                }
            }
        }

        return ans;

    }
};
