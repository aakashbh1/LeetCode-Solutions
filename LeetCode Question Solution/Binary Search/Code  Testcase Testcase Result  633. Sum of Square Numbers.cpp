class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i=0;
        long long j=sqrt(c);
        while(i<=j){
            long long sum=i*i+j*j;
            if(sum==c) return 1;

            else if( sum>c) j--;
            else i++;
        }
        return 0;
    }
};
