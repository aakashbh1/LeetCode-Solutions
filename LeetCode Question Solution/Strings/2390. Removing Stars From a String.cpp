class Solution {
public:
    string removeStars(string s) {
       string res="";
       for(int i=0;i<s.length();i++){
           if(s[i]!='*') res.push_back(s[i]);
           else res.pop_back();
       } 
       return res;
    }
};
