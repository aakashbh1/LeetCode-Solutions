   int n,m,s;
    vector<int> dx={-1,-1,-1,0,1,1,1,0};
    vector<int> dc={-1,0,1,1,1,0,-1,-1};
    
    bool solve(int i, int j,vector<vector<char>>&grid, string &word, int ind, int k){
        if(ind==s) return true;
        if(i>=0 &&i<n&&j>=0&&j<m&&grid[i][j]==word[ind]) 
        return solve(i+dx[k],j+dc[k],grid,word,ind+1,k);
        return false;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    n=grid.size();
	    m=grid[0].size();
	     s=word.size();
	    vector<vector<int> >ans;
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==word[0]){
	                for(int k=0;k<8;k++){
	                    if(solve(i+dx[k],j+dc[k],grid,word,1,k)){
	                        ans.push_back({i,j});
	                        break;
	                    }
	                }
	            }
	        }
	    }
	    return ans;
	    
	}
