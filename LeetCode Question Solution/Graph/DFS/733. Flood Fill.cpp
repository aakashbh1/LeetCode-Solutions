733. Flood Fill
class Solution {
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int color, int x){
        if(sr<0 or sr>=image.size() or sc<0 or sc>=image[0].size()or image[sr][sc]!=x or image[sr][sc]==color) return;
        image[sr][sc]=color;
        vector<pair<int,int>> direction={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto dir :direction){
            int new_x=sr+dir.first;
            int new_y=sc+dir.second;
            dfs(image, new_x, new_y, color,x);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int x=image[sr][sc];
        dfs(image,sr,sc,color,x);
        return image;
    }
};
