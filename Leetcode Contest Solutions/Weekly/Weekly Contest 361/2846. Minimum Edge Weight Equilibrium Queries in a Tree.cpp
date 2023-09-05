class Solution {
    vector<vector<int>> v;
    vector<vector<int>> dp;
    vector<vector<pair<int,int>>> tree;
    vector<int> height;
public:
    void binary_lifting(int node,int parent,vector<int>&v1,int level)
    {
        v[node] = v1;
        dp[node][0] = parent;
        height[node] = level;
        for(int i = 1 ; i < 15 ; ++i)
            if(dp[node][i-1] != -1) dp[node][i] = dp[dp[node][i-1]][i-1]; 
        for(auto &x : tree[node])
        {
           if(x.first != parent)
           {
                ++v1[x.second];
                binary_lifting(x.first,node,v1,level+1);
                --v1[x.second];
           }
        }
    }
    int lift(int node,int jump)
    {
        for(int i = 14 ; i >= 0 ; --i)
        {
            if(node == -1) return node;
            if(jump&(1<<i))
                node = dp[node][i];
        }
        return node;
    }
    int ancestor(int a,int b)
    {
        if(height[a] < height[b]) swap(a,b);
        a = lift(a,height[a]-height[b]);
        if(a == b) return a;
        for(int i = 14 ; i >= 0 ; --i)
        {
            if(dp[a][i] != dp[b][i])
            {
                a = dp[a][i];
                b = dp[b][i];
            }
        }
	    return lift(a,1);
    }
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int m = queries.size();
        v = vector<vector<int>>(n);
        dp = vector<vector<int>>(n,vector<int>(15,-1));
        tree = vector<vector<pair<int,int>>>(n);
        height = vector<int>(n);
        for(auto &x : edges)
        {
            tree[x[0]].push_back({x[1],x[2]-1});
            tree[x[1]].push_back({x[0],x[2]-1});
        }
        vector<int> v1(26,0);
        binary_lifting(0,-1,v1,0);
        vector<int> ans;
        for(auto &x : queries)
        {
            int k = ancestor(x[0],x[1]);
            vector<int> v2(26,0);
            int maxi(0),s(0);
            for(int i = 0 ; i < 26 ; ++i)
            {
                v2[i] = v[x[0]][i] + v[x[1]][i] - 2*v[k][i];
                s += v2[i];
                maxi = max(maxi,v2[i]);
            }
            ans.push_back(s-maxi);
        }
        return ans;
    }
};
