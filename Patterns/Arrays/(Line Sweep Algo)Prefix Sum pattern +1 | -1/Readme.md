So Line Sweep Algorithm is commonly used whenever we are given number  
like start and end but somehow question demands for elements in between also  
So we use this algorithm to mark all the points from start to end so that we can get our result   

Process:  
1. make an array of input size in which we will mark elements from start to end   
2. mark start as +1 and end+1 as -1,  reason behind this is to nullify the effect of after the start and end   
3. then we use a for loop to evaluate the answer accordingly   


Template: 
          
            int numberOfPoints(vector<vector<int>>& nums){
              int n = nums.size() ; 
              int pref[150] = {0} ;
              int ans = 0 ;  
              for(int i=0; i<n; i++)
              {
                  pref[nums[i][0]]++ ; // start as +1
                  pref[nums[i][1]+1]-- ; // end+1 as -1 
              }
              for(int i=0; i<110; i++)
              {
                  pref[i+1] += pref[i] ; // add previous value to next value so that we can nullify that -1 
                  // initially --> 0 1 0 0 0 -1 +1 0 0 0 0 -1
                  // after this loop --> 0 1 1 1 1 0 1 1 1 1 0 so total elemnts were 8 in start and end 
                  if(pref[i]>0) ans++ ;// it means that value was between start and end
                  cout<<pref[i]<<" ";
              }
              return ans ;
          }
          
