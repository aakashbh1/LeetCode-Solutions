class Solution {
public:
    int findNthDigit(int n) {
        long long digit=1, base=9, total=0;
        while(total+digit*base<n){
            total+=digit*base;
            digit++;
            base*=10;
        }

        n-=total;
        int num= pow(10, digit-1);
        num+=(n-1)/digit;
        int index=(n-1)%digit;
        string s=to_string(num);
        return s[index]-'0''
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
