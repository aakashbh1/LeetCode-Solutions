class Solution {
public:
    void solveFunction(int start, int k, int n,vector<int> temp, vector<vector<int>> &result){
        if(k==0){
            result.push_back(temp);
            return;
        }

        for(int i=start;i<=n;i++){
            temp.push_back(i);
            solveFunction(i+1,k-1,n,temp,result);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        solveFunction(1,k,n,temp,result);
        return result;


    }
};
