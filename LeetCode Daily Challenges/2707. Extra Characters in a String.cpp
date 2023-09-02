class Solution {
public:
    unordered_set<string> st;
    int t[51];
    int n;
    int solve(string &s, int idx) {
        if (idx >= n) // we check for all character in string  
            return 0;
            if(t[idx] != -1) return t[idx];
        string currStr = ""; // create string to store current string 
        int minExtra = n;// minExtra goes till n in case of no any matching   
        for (int i = idx; i < s.size(); i++) {
            currStr.push_back(s[i]);

            int currExtra = (st.find(currStr) == st.end()) ? currStr.length() : 0;
            int nextExtra = solve(s, i + 1);// further recursion call for next character 
            int totalExtra = currExtra + nextExtra;
            minExtra = min(minExtra, totalExtra); 
        }
        return  t[idx] =minExtra;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        memset(t , -1 , sizeof(t));
        for(string &word : dictionary) {
            st.insert(word);
        }
        return solve(s, 0);
    }
};
