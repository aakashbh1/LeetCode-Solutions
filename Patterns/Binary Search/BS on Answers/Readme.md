In this patter we are needed to find maximum or minimum but binary search is not clearly visible at first glanse  
But in this type of pattern there is range which is fixed for answers so it is also known as binary search on answer   
We have a low and high of answer in which it will lie.   
Then we have a check function which check if current answer is possible or not and on that basis aur low and high moves.  


Psuedo Code:


    // check function 
    it can be any thing that is checking the current value if it can be a answer  
    any kind of fucntion is allowed  
    
    // Binary Search  
    int low;// min value of answer
    int high;// max value of answer 
    int ans;
    while(low<=high){
      int mid =low+(high-low)/2;
      if(check(mid)==true){
      ans=mid; // this could be the answer
      high=mid-1; // more smaller answer can be possible if mid was possible
      }
    
    else low=mid+1; // as mid was not the answer so move low 
     }
     return ans;
one more way to code:

    while(low<high){ not equals to 
          int mid =low+(high-low)/2;
          if(check(mid)==true){
          ans=mid; // this could be the answer
          high=mid; // more smaller answer can be possible if mid was possible
          }
        
        else low=mid+1; // as mid was not the answer so move low 
         }
