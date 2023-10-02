class Solution{
  public:	
    void recur(int index, string s, unordered_set<string> &st, string &temp){
        
        if(index>=s.length()){
            st.insert(temp);
            return ;
        }
        
        recur(index+1,s,st,temp);
        temp.push_back(s[index]);
        recur(index+1,s,st,temp);
        temp.pop_back();
        
    }
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    string temp="";
	    unordered_set<string> myset;
	    recur(0,s,myset,temp);
	    return myset.size();
	}
};
