//Iterative
class Solution {
public:
   
    int brokenCalc(int startValue, int target) {
      int count=0;
      while(target>startValue){
          if(target&1) target++;
          else target/=2;
          count++;
      }
      return count+startValue-target;
    }
};

//Recursive
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        
        if(startValue >= target) return startValue - target;
        
        return (target%2==0) ? 1 + brokenCalc(startValue, target/2) : 1 + brokenCalc(startValue, target+1);
    }
};
