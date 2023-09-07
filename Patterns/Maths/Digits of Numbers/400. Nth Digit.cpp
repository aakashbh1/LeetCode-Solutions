class Solution {
public:
    int findNthDigit(int n) {// example is 15th digit 
        long long digit=1, base=9, total=0;
        while(total+digit*base<n){
            total+=digit*base;//9,180+9,........
            digit++;//1 ,2,3,
            base*=10;// 9,90,900
        }

        n-=total; //(15-9=6)
        int num= pow(10, digit-1);//10
        num+=(n-1)/digit;//10+2=12 it means the number is 12
        int index=(n-1)%digit; // index of number 12 which is the 11th digit 
        string s=to_string(num);
        return s[index]-'0';
    }
};
// class Solution {
// public:
//     int findNthDigit(int n) {
//         int ans=0;
//         int i=1;
//         while(ans<n){
//             string s=to_string(i);
//             ans+=s.length();
//             i++;
//             if(ans==n) return s[s.length()-1]-'0';
//             if(ans>n) return s[s.length()-1-(ans-n)]-'0';
//         }
//         string s=to_string(i);
//         ans+=s.length();
//         if(ans==n) return s[s.length()-1]-'0';
//         if(ans>n) return s[s.length()-(ans-n)]-'0';

//         return -1;
//     }
// };
