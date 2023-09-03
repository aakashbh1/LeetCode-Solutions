class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> v1; // stores even indices of s1
        vector<int> v2; // stores odd indices of s1
        vector<int> v3; // stores even indices of s2
        vector<int> v4; // stores odd indices of s2
        
        if(s1.length()!=s2.length()) return 0;
        
        for(int i=0;i<s1.length();i++){
            if(i%2==0 ){ // even indices of both s1 and s2
                v1.push_back(s1[i]); // storing values 
                v3.push_back(s2[i]);// storing values 
            }
            else {
                v2.push_back(s1[i]);// storing values 
                v4.push_back(s2[i]);// storing values 
            }
        }
         // sorting all the vectors so that we can compare them
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        sort(v3.begin(),v3.end());
        sort(v4.begin(),v4.end());
         

        // as we can swap any even indices with any other even 
        //indices and also any odd index with any othet odd index in 
        // s1 so we just stored them all together 

        if(v1==v3 && v2==v4) return 1; // comparing v1 with v3  
                                    // and v2 with v4
        return 0;
    }
};
