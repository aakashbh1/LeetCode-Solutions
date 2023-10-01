class Solution {
public:
    long long dfs(int &ans, vector<int> &values, int node, int prevNode, unordered_map<int, list<int>>&adj, int &k){
         //postorder
         long long sum=values[node];
         for(auto it:adj[node]){
             if(it==prevNode) continue;
             sum+=dfs(ans,values,it,node,adj,k); // l and r 
         }

         if(sum%k==0) {
             ans++; // actions on node 
             return 0;
         }
         else return (long long ) sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int, list<int> >adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt=0;
        dfs(cnt, values, 0,-1,adj,k);
        return cnt;
    }
};
