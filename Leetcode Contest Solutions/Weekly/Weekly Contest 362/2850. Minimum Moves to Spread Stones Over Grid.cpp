class Solution {
public:
int solve(int idx,vector<pair<int,int>>&extras,vector<pair<int,int>>&zeroes,vector<vector<int>>&grid){
    if(idx==zeroes.size()){
        return 0;
    }
    int ans=INT_MAX;
    for(int i=0;i<extras.size();i++){
        int x=extras[i].first;
        int y=extras[i].second;
        if(grid[x][y]>1){
            grid[x][y]--;
            grid[zeroes[idx].first][zeroes[idx].second]++//==1;//this line is not complusion
            ans=min(ans,abs(zeroes[idx].first-x)+abs(zeroes[idx].second-y)+solve(idx+1,extras,zeroes,grid));
            grid[x][y]++;
            grid[zeroes[idx].first][zeroes[idx].second]--//==0;//this line is not complusion
        }
    }
    return ans;
}
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int,int>>extras;
        vector<pair<int,int>>zeroes;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==0){
zeroes.push_back({i,j});
                }
                if(grid[i][j]>1){
                   extras.push_back({i,j});
                }
            }

        }
        return solve(0,extras,zeroes,grid);
    }
};
