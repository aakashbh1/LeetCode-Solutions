//Disjoint Set Union (DSU)

/*
    
    -> Disjoint set is used to find whether two elements belong to the same group or not in constant time
    -> Algorithm
        -> We have to maintain two vector rank and parent to store the current rank of a given node 
           and parent of node
        -> For checking if two nodes belong to the same parent their ultimate parent must be same
        -> Union Operation
            -> If the parent comes out to be same then return, that means they belong to same group
            -> Else if the rank of left is greater than right than left becomes the parent of right which 
               ensures no increase in the rank of the former
            -> If the rank is same it does not matter who becomes the parent of whom just increase the rank
               by one and assign the parent
        -> Find operation uses simple recursion to find the parent and also used for path comperession
        
    
*/

class DisjointSet{
    vector<int> rank, parent, size;
    public: 
    // Constructor
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 0);
        
        // Ensures 1 Based indexing graph also
        for(int i = 0 ; i <= n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    };

    // Find Operation with path compression
    int find(int node){
        if(parent[node] == node)return node;
        else return parent[node] = find(parent[node]);
    };
    
    // Union operation by rank
    void unionbyrank(int x, int y){
        int ult_parent_x = find(x);
        int ult_parent_y = find(y);
        
        // They already belongs to the same group
        if(ult_parent_x == ult_parent_y)return;
        
        // They belong to different groups, based on ranking the union operation will be broken in three pieces
        if(rank[ult_parent_x] > rank[ult_parent_y]){
            parent[ult_parent_y] = ult_parent_x;
        }else if(rank[ult_parent_x] < rank[ult_parent_y]){
            parent[ult_parent_x] = ult_parent_y;
        }else{
            parent[ult_parent_x] = ult_parent_y;
            rank[ult_parent_y] += 1;
        }
    }
    
    // Union operation by size
    void unionbysize(int x, int y){
        int ult_parent_x = find(x);
        int ult_parent_y = find(y);
        
        // They already belongs to the same group
        if(ult_parent_x == ult_parent_y)return;
        
        // They belong to different groups, based on ranking the union operation will be broken in three pieces
        // x component bigger 
        if(size[ult_parent_x] > size[ult_parent_y]){
            parent[ult_parent_y] = ult_parent_x;
            size[ult_parent_x] += size[ult_parent_y];
        // y component bigger or both same
        }else{
            parent[ult_parent_x] = ult_parent_y;
            size[ult_parent_y] += size[ult_parent_x];
        }
    }
};

//################################################################################################
//Prims Algorithm

class Solution {
public:
	// Prims Algorithm
    int prims(map< int, vector<pair < int, int >> >adj, int V){
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;
        
        // Extras
        vector<int> dist(V, INT_MAX), parent(V, -1);
		int nodes = 0;
        dist[0] = 0;
        
        // MST
        vector<int> vis(V, 0);
        pq.push({0, 0});
		int totalSum = 0;
        
        while(!pq.empty() && nodes < V){
           auto it = pq.top();
           int distance = it.first;
           int node = it.second;
           pq.pop();
          
           // Checking if the node already exists in the MST or not, vis[node] means adding to the MST
           if(vis[node])continue;
           totalSum += distance;
           vis[node] = 1;
           nodes++;
           
           // Adding its adjacent nodes
           for(auto it : adj[node]){
               int childW = it.second;
               int childN = it.first;
               
               // If the child node is not already visited add it to the pq to process on it 
               if(!vis[childN]  && childW < dist[childN]){ // Dijkstra Differs here
                   // Extras
                   dist[childN] = childW; 
                   parent[childN] = node;
                   pq.push({childW, childN});
               }
           }
           
        }
        //for(int i:dist) ans += i;//dist array will have min dist require to travel there from a node
        return totalSum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        // Creating adjacency list
        int n = points.size();
        
        map< int, vector<pair < int, int >> >adj;
		
        // Assume i and j as two nodes connected with a weight of 
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                int x = points[i][0];
                int y = points[i][1];
                
                int xx = points[j][0];
                int yy = points[j][1];
                
                int w = abs(xx - x) + abs(yy - y);
                adj[i].push_back({j, w});
                adj[j].push_back({i, w});
            }
        }
        
        return prims(adj, n);
    }
};

//################################################################################################

//Kruskal

int kruskal(map< int, vector<pair < int, int >> >adj, int n){
        vector<pair<int, pair<int, int>>> edges;
        vector<vector<int>> MST;
        for(int i = 0 ; i < n ; i++){
            for(auto it : adj[i]){
                int node = i;
                int adjNode = it.first;
                int weight = it.second;
                
                edges.push_back({weight, {node, adjNode}});
            }
        }
        int totalWeight = 0;
        DisjointSet ds(n);
        sort(edges.begin(), edges.end());
        for(auto i : edges){
            int weight = i.first;
            int node = i.second.first;
            int adjNode = i.second.second;
            
            // They do not belong to the same group
            if(ds.find(node) != ds.find(adjNode)){
                MST.push_back({node, adjNode});
                totalWeight += weight;
                ds.unionbysize(node, adjNode);
            }
        }
        // Printing the MST
        for(auto i : MST){
            for(auto j : i){
                cout << j << " ";
            }
            cout << endl;
        }
        
        return totalWeight;
    }
