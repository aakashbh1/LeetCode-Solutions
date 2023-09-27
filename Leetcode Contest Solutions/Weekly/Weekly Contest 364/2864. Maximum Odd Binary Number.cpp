class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1') count++;
        }
        
        string res="";
        
        
        for(int i=0;i<s.length()-1;i++){
            if(count>1){
                res.push_back('1');
                count--;
            }
            else res.push_back('0');
        }
        res.push_back('1');
        return res;
    }
};
