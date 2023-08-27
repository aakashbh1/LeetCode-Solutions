class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        unordered_set<long long int> s;
        vector<long long> ans;
        long long int i=1;
        while(ans.size()<n){
            if(s.count(i)==false){
                ans.push_back(i);
                s.insert(target-i);    
            }
            i++;
            if(ans.size()==n) break;
        }
        long long sum= accumulate(ans.begin(),ans.end(),0LL);
        return sum;
    }
};
