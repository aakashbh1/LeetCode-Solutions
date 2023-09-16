 Isme simple hai 2 tarike hai with and without for loop dono backtrack ke hi templates hai.

Template 1 :
// ek Element lo  
// explore karo (matlab function call karo next)  
// Element hata do jisme daala tha  
// Ab explore karo uss element ko bina liye  

Code:
   
        temp.push_back(arr[i]);                   // ek Element lo
        solve(i,arr,ans,temp,t-arr[i]);           // explore karo (matlab function call karo next)                                                    
        temp.pop_back();                          // backtracking // Element hata do jisme daala tha
        solve(i+1,arr,ans,temp,t);                // nottake // Ab explore karo uss element ko bina liye 
        
        //iss case mei uss element ko wapas le sakte hai but har baar aisa nhi hoga

        or*****$$$$$$
        // pehle exclude kar lo simple sa
        solve(i+1,arr,ans,temp,t);
        // ab include kar do
        temp.push_back(arr[i]);
        solve(i+1,arr,ans,temp,t);


Template 2 : Using For Loops 

// For loop initiation  
// ek element daalo   
// explore karo next  
// element nikalo   


Code:

       for(int i = start; i <= n; i++) {
            temp.push_back(i);
            solve(i+1, n, k-1, temp);
            temp.pop_back();
        }
