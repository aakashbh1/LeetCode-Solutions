class Solution {
public:
    void util(vector<string>& res, int open, int close, string& tmp, int n)
    {
        if(tmp.length()==2*n) {res.push_back(tmp); return;}
        if(open<n){
            tmp.push_back('(');
            util(res,open+1,close,tmp,n); //if(open<n)generate(open+1,close,n,s+"("); works the same as we add it in the function call so it automatically
            tmp.pop_back();							// gets removed(pop) whenever function backtracks
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
class Solution {
public:
vector<string>ans;
   void generate (int open,int close ,int n,string s){
       if(s.size()==2*n)ans.push_back(s);
       if(open<n)generate(open+1,close,n,s+"(");
       if(close<open)generate(open,close+1,n,s+")");
   }
    vector<string> generateParenthesis(int n) {
        generate(0,0,n,"");
        return ans;
    }
};
