class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> unique;

        for (int i = 0; i < s.size(); i++) {
            unique[s[i]]++;
        }

        unordered_set<int> t;
        int cnt = 0;

        for (auto it : unique) {
            if (t.count(it.second) > 0) {
                while (t.count(it.second) != 0) {
                    it.second--;
                    cnt++;
                }
            }

            if (it.second != 0)
                t.insert(it.second);
        }

        return cnt;
    }
};
Approach 2:
class Solution {
public:
    int minDeletions(string s) {
        int arr[26] = {0};
        for(auto i : s)
        {
            arr[i-'a']++;
        }
        int ans = 0;
        sort(arr,arr+26);
        for(int i=24;i>=0;i--)
        {
            if(arr[i+1]>arr[i])
            {
                continue;
            }
            while(arr[i] > 0 && arr[i]>=arr[i+1])
            {
                ans++;
                arr[i]--;
            }
        }
        return ans;
    }
};
