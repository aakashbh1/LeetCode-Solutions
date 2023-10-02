void helper(string s, int ind, set<string>&st) {
            if(ind == s.size() - 1) {
                st.insert(s);
                return;
            }
            swap(s[ind], s[ind+1]); // Swap adjacent characters
            helper(s, ind+1, st);   // Recur for the rest of the string
            swap(s[ind], s[ind+1]); // Restore the original order

            helper(s, ind+1, st);   // Recur without swapping (backtracking)
        }
	
		vector<string>find_permutation(string S)
		{
		    vector<string>ans;
		    set<string>st;
		    helper(S, 0, st);
		    for(auto it : st) ans.push_back(it);
		    return ans;
		}
