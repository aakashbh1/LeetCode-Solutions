class Solution {
public:
    string minimumString(string a, string b, string c) {        
        string nums[] = {a, b, c};
        int n = sizeof(nums) / sizeof(nums[0]);       
        string resultString = "";
        for (int i = 0; i < n; i++) {          
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {  
                    if (i != j && j != k && i != k) {
                        string str1 = solve(nums[i], nums[j]);     
                        string str2 = solve(str1, nums[k]);
                        if (resultString.empty() || str2.length() < resultString.length()  ||(str2.length() == resultString.length() && str2 < resultString)) {                                                resultString = str2;
                        }    
                    }
                }       
            }
        }       
        return resultString;
    }   
    string solve(string m, string n) {
        if (m.find(n) != string::npos) {    
            return m;
        }      
        for (int i = min(m.length(), n.length()); i >= 0; i--) {
            
            if (m.substr(m.length() - i) == n.substr(0, i)) {   
                return m + n.substr(i);
            }      
        }
        return m + n; 
    }
};
