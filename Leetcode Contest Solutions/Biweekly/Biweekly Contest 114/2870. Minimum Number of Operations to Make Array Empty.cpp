class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        int operations = 0;

        for (auto& pair : counts) {
            if(pair.second<2) return -1;
            
            int div= pair.second/3;
            int mod=pair.second%3;

            if(mod==0) operations+=div;
            if(mod==1) operations+=div-1+2;
            if(mod==2) operations+=div+1;    
        }
        
        return operations;
    }
};
