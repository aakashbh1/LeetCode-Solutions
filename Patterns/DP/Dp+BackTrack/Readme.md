Iss type ke questions mei normally take not take ka ki funda chalta hai bas isme hume all possible cases return karne padte hai toh Dp and backtrack mix lagta hai.
Iska bhi template code fix hi hai ek jaisa hi hai...
agar mujhe mila toh mei pakke se add kar dunga 

Template 1 of Backtrack is normal use without For Loop :
Code: 

        int solve(vector<int>& nums, int target, int idx) {
        if(target == 0)
            return 1;
        
        if(idx >= n || target < 0)
            return 0;
        
        if(t[target][idx] != -1)
            return t[target][idx];
        
        int take_idx    = solve(nums, target - nums[idx], 0); // index lo and explore karo 
        int reject_idx  = solve(nums, target, idx+1); // index mat lo 
        
        return t[target][idx] = take_idx + reject_idx;
        
    }


Template 2 of BackTrack with For Loop :
Code:


           int solve(int idx, vector<int>& nums, int target) {
        if(target == 0)
            return 1;
        
        if(idx >= n || target < 0)
            return 0;
        
        int result = 0;
        
        if(t[target][idx] != -1)
            return t[target][idx];
        
        for(int i = idx; i<n; i++) {     // Yaha pe not take ka kaam for loop kar rha hai as usme index 
                                         //aage badh rhi hai apne aap toh uss index toh woh apne aap exclude kar hai 
            int take_i   = solve(0, nums, target-nums[i]);
            
            result += take_i;
        }
        
        return t[target][idx] = result;
    }
