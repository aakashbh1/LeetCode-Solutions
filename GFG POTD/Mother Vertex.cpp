class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(vector<int >adj[] , int V , int start , vector<int >& vis ){
        vis[start] = 1;
        for (auto it:adj[start]){
            if (!vis[it] ){
                dfs(adj , V , it , vis );
            }
        }
    }
int findMotherVertex(int V, vector<int>adj[])
{
    // Code here
    vector<int >vis(V, 0);
    int lastnode =0;
    for (int i =0;i< V ;i++){
        if (vis[i] ==0 ){
            dfs(adj,V , i, vis);
            lastnode =i ; // store kr liya humne ki yeh potential node ho sakta 
          // jaise agar 4 se dfs kiya pehle toh usse conntected 5,6 say mark ho gaye but 0,1,2,3 reh gaye toh unke liye dfs call hoga aur woh potential 
          // node banenge as 4 toh nhi hi hoga 
        }
    }
    for (int i=0;i< V ;i++){
        vis[i]= 0; // visited array ko re-intialise kar diya 0 se
    }
    dfs(adj, V , lastnode , vis); // potential se dfs kiya aur agar count V aa gaya fir return kar do 
    
    for (int i=0; i< V ;i++){
        if (vis[i] ==0 ) {
            return -1;
        }
    }
    
    return lastnode ;
    
        
}
};
