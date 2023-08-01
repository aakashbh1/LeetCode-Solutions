//with loop
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
//Khandani Backtracking Approach (without for loop)
class Solution {
public:
    vector<vector<int>> result;
    
    void solve(int start, int n, int k, vector<int>& temp) {
        if(k == 0) {
            result.push_back(temp);
            return;
        }
        
        if(start > n)
            return;
        
        temp.push_back(start);
        solve(start+1, n, k-1, temp);
        temp.pop_back();
        solve(start+1, n, k, temp);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        
        solve(1, n, k, temp);
        
        return result;
    }
};
