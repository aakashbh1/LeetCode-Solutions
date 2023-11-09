class Solution {
public:
    int countHomogenous(string s) {
        long long int d=pow(10,9)+7;
        int res=0;
        for(int i=0;i<s.length();){
            int cnt=1;
            while(i<s.length()-1 && s[i]==s[i+1]){
                cnt=(cnt+1)%d;
                i++;
            }
            int temp=((cnt%d)*((cnt+1)%d)/2)%d;
            res=(res+temp)%d;
            i++;
        }
        return res%d;
        
    }
};
