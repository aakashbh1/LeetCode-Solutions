DFS
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        vector<int>color(n+1,-1);
        for(int i = 0; i < dislikes.size(); ++i){
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 1; i <= n; ++i){
            if(color[i] == -1){
                if(!bipartiteDfs(i,adj,color)) return false;
            }
        }
        return true;
    }
    bool bipartiteDfs(int node,vector<int>adj[],vector<int>& color){
        
        for(auto& edges: adj[node]){
            if(color[edges] == -1){
                color[edges] = 1 - color[node];
                if(!bipartiteDfs(edges,adj,color)) return false;
            }
            else if(color[edges] == color[node]) return false;
        }
        return true;
    }
};
BFS
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        vector<int>color(n+1,-1);
        for(int i = 0; i < dislikes.size(); ++i){
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 1; i <= n; ++i){
            if(color[i] == -1){
                if(!bipartiteBfs(i,adj,color)) return false;
            }
        }
        return true;
    }
    bool bipartiteBfs(int i,vector<int>adj[],vector<int>& color){
        queue<int>q;
        q.push(i);
        color[i] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &it:adj[node]){
                if(color[it] == -1){
                    color[it] = 1-color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]) return false;
            }
        }
        return true;
    }
};
