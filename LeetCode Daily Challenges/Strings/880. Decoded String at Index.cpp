My approach this is correct my MLE
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        
        string res="";
        string temp="";
        for(int i=0;i<s.length();i++ ){
            if(int(s[i])>=97 and int(s[i])<=122){
                temp+=s[i];
            }
            else {
                string mid=temp;
                
                int x=(s[i]-'0')-1;
                while(x--){
                    temp=temp+mid;
                }
            }
        }

        res=temp[k+1];
        return res;
    }
};

// second appraoch 
 string decodeAtIndex(string S, int K) {
        
        int n = S.length();
        long long size = 0;
        
        for(char ch:S) {
            if(isdigit(ch)) {
                size = size*(ch-'0');
            } else {
                size++;
            }
        }
        
        for(int i = n-1; i>=0; i--) {
            K = K%size;
            
            if(K == 0  && isalpha(S[i]))
                return string(1, S[i]);
            
            if(isalpha(S[i]))
                size--;
            else
                size = size/(S[i]-'0');
        }
        
        return "";
    }
