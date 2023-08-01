class Solution {
public:
    int m;
    int n;
    int emptyCells;
    int result=0;
    vector<vector<int>> directions={{1,0},{-1,0},{0,1},{0,-1}};

    void visitPath(vector<vector<int>> &grid, int curr_count,int i, int j){
        if(i<0||i>=m||j<0||j>=n|| grid[i][j]==-1) return;
        if(grid[i][j]==2){
            if(curr_count==emptyCells) result++;
            return;
        }
        grid[i][j]=-1;
        for(auto &dir: directions){
            int new_x=i+dir[0];
            int new_y=j+dir[1];
            visitPath(grid,curr_count+1,new_x,new_y);
        }

        grid[i][j]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        result=0;
        emptyCells=0;
        int start_x=0;
        int start_y=0;
        int curr_count=0;


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)emptyCells++;
                if(grid[i][j]==1){
                    emptyCells++;
                    start_x=i;
                    start_y=j;
                }
            }
        }

        visitPath(grid,curr_count,start_x,start_y);
        return result;

    }
};
