class Solution {
public:
    int dp[101010];
    int ans;
    void dfs(int node,int par,vector<pair<int,int>>adj[]){
        dp[node]=0;
        for(auto child : adj[node]){
            if(child.first==par)
                continue;
            if(child.second==0)
                ans++;
            dfs(child.first,node,adj);
        }
        dp[node]=ans;
    }
    void dfs2(int node,int par,vector<pair<int,int>>adj[],vector<int>&queries){
        
        for(auto child : adj[node]){
            if(child.first==par)
                continue;
            if(child.second==0)
                queries[child.first]=(queries[node]-1);
            else
                queries[child.first]=(queries[node]+1);
            // cout<<"child"<<child.first<<" node"<<node<<endl;
            // cout<<queries[child.first]<<" "<<queries[node]<<" "<<(child.second)<<endl;
            dfs2(child.first,node,adj,queries);
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<int>queries(n,0);
        vector<pair<int,int>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],1});
            adj[edges[i][1]].push_back({edges[i][0],0});
        }
        for(int i=0;i<n;i++){
            ans=0;
            dfs(i,-1,adj);
            queries[i]=dp[i];
            break;
        }
        dfs2(0,-1,adj,queries);
        return queries;
    }
};
