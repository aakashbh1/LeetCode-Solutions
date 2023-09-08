// My Approach
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        vector<int> prev = {1};

        for (int i = 0; i < numRows-1; i++) {
            vector<int> curr;
            curr.push_back(1);
            for (int j = 0; j < prev.size() - 1; j++) {
                curr.push_back(prev[j] + prev[j + 1]);
            }
            curr.push_back(1);
            ans.push_back(curr);
            prev = curr;
        }

        return ans;
    }
};

// Approach 2 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for(int i = 0; i<numRows; i++) {  
            result[i] = vector<int>(i+1, 1);     
            for(int j = 1; j < i; j++) {        
                result[i][j] = result[i-1][j] + result[i-1][j-1];       
            }    
        }
        return result;
    }
};
