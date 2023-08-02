class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2)// if odd size 
            return {};
        
        unordered_map<int,int> m;
        sort(changed.begin(),changed.end());
        // we will take elements in increasing order
        vector<int> res;
        for(auto x:changed)
        {
            m[x]++;
        }
        for(auto x:changed)
        {
            if(m[x]>0)// this element is not a double of any other element
            {
                m[x]--;
                if(m[2*x]>0)// we got 2x for the x
                {
                    res.push_back(x);
                    m[2*x]--;
                }
                else // we didn't got the 2x for the x
                    return {}; 
            }
            else
            {
                // do nothing as this element x was already a double of some smaller element
            }
        }
        return res;
    }
};
