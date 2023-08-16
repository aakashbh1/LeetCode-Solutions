//BFS
class Solution {
public:
void bfs(map<pair<int,int>,bool>& visited,int row,int col,vector<vector<char>>& grid){
    queue<pair<int,int>> q;
    q.push({row,col});
    visited[{row,col}]=true;
    while(!q.empty()){
        auto fNode=q.front();
        int x=fNode.first;
        int y=fNode.second;
        q.pop();
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newX=x+dx[i];
            int newY=y+dy[i];
            if((newX>=0&&newX<grid.size())
            &&(newY>=0&&newY<grid[0].size())
            &&!visited[{newX,newY}]
            &&grid[newX][newY]=='1')
            {
                q.push({newX,newY});
                visited[{newX,newY}]=true;
            }
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        map<pair<int,int>,bool> visited;  

        int count=0;
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(!visited[{row,col}]&& grid[row][col]=='1'){
                bfs(visited,row,col,grid);
                count++;
                }
            }
            
        }
        return count;
    }
};


//DFS
 void dfs(vector<vector<int>> &vis, int row, int col, vector<vector<char>>& grid){
        int n = grid.size(); 
        int m = grid[0].size();
        vis[row][col] = 1;
    
        int delrow[] = {0,1,0,-1};
        int delcol[] = {1,0,-1,0};

        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == '1'
            && !vis[nrow][ncol]){
                dfs(vis,nrow,ncol,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        int count = 0; 
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(vis,i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};
