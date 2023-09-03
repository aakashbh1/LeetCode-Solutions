// 2839. Check if Strings Can be Made Equal With Operations I
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        
        if(s1==s2) return 1;
        
        string res=s1;
          swap(res[1],res[3]);
        if(res==s2) return 1;
        swap(s1[0],s1[2]);
        if(s1==s2) return 1;
        
        
        swap(s1[1],s1[3]);
        if(s1==s2) return 1;
        
        return 0;
        
        
    }
};
