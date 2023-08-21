class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        
        string res="";
        for(int i=0;i<words.size();i++){
            res+=words[i][0];
        }
        
        if(res==s) return true;
        return false;
    }
};
