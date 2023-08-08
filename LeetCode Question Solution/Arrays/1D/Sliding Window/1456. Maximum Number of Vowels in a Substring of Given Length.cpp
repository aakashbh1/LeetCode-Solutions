class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0,j=0,count=0,maxi=0;
        while(j<k){
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')
            count++;

            j++;
        }
        
       
       maxi=max(maxi,count);
    //    return count;

        while(j<s.length()){
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')
                 count++;
            j++;
             if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                 count--;
            i++;
            maxi=max(maxi,count);
        }

        return maxi;
    }
};
