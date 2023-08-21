 int Count(vector<vector<int> >& matrix) {
        vector<vector<int>> dir={ {1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1} };
        
        int n=matrix.size();
        int m=matrix[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int countofZero=0;
                if(matrix[i][j]==1){
                    for(auto &x: dir){
                        int new_x=i+x[0];
                        int new_y=j+x[1];
                        if(new_x>=0 && new_x<n && new_y<m && new_y>=0 ){
                            if(matrix[new_x][new_y]==0) countofZero++;
                        }
                    }
                     if(countofZero==0)continue;
                     if(countofZero%2==0) count++;
                }
               
            }
        }
        return count;
    }
