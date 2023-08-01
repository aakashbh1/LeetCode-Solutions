//Observation 
class Solution {
public:
  
    int addDigits(int num) {
        if(num==0) return 0;
        if(num%9==0) return 9;
        return num%9;
    }
};


//Solution 1: find by modulo and divide

class Solution {
public:
    int sum=0;
    int countDigits(int n){
        int count=0;
        sum=0;
        while(n!=0){
            sum+=n%10;
            n=n/10;
            count++;
        }
        return count;

    }
    int addDigits(int num) {
        while(countDigits(num)>1){
            num=sum;
        }
        return num;


    }
};
