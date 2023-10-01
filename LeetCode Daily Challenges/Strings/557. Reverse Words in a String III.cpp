class Solution {
public:
    void rev (string &s, int  start, int  end){
        int i=start;
        int j=end;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }

    }
    string reverseWords(string s) {
        int start=0;
        int end=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                end++;
            }
            else{
                rev(s,start,end);
                start=i+1;
                end=i;
            }
        }
        rev(s,start,end);
        return s;
    }
};
