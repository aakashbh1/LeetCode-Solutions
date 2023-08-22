int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        vector<long long int> ans1;
        vector<long long int> ans2;
        
        for(int i=0;i<n;i++){
            long long int sum1=0;
            long long int sum2=0;
            for(int j=0;j<n;j++){
                sum1+=matrix[i][j];
                sum2+=matrix[j][i];
            }
            ans1.push_back(sum1);
            ans2.push_back(sum2);
        }
        long long int maxi1=*max_element(ans1.begin(),ans1.end());
        long long int maxi2=*max_element(ans2.begin(),ans2.end());
        long long int res1=0;
        long long int res2=0;
        for(int i=0;i<ans1.size();i++){
            if(ans1[i]!=maxi1){
                res1+=maxi1-ans1[i];
            }
        }
        for(int i=0;i<ans2.size();i++){
            if(ans2[i]!=maxi2){
                res2+=maxi2-ans2[i];
            }
        }
        
        return max(res1, res2);
    } 
