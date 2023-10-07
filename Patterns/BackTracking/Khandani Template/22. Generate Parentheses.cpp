class Solution {
public:
    void util(vector<string>& res, int open, int close, string& tmp, int n)
    {
        if(tmp.length()==2*n) {res.push_back(tmp); return;}
        if(open<n){
            tmp.push_back('(');
            util(res,open+1,close,tmp,n);
            tmp.pop_back();
        }
        if(close<open){
            tmp.push_back(')');
            util(res,open,close+1,tmp,n);
            tmp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open=0,close=0; // open -> number of open brackets
						 // close -> number of close brackets
        vector<string> res;
        if(n==0) return res;
        string temp="";
        util(res,open,close,temp,n);
        return res;
    }
};
