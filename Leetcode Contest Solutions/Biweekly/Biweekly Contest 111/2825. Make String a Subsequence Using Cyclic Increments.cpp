class Solution {
public:
    bool isNextChar(char c1, char c2) {
        if(c1=='z')c1='a';
        else c1=c1+1;
        return (c1 == c2);
    }
    
    bool canMakeSubsequence(string str1, string str2) {
        if (str2.length() > str1.length()) {
            return false;
        }
        int countOfLetters = 0;
        for (int i = 0; i < str1.length() && countOfLetters < str2.length(); i++) {
            if (str1[i] == str2[countOfLetters] ) {
                countOfLetters++;
            } else if (isNextChar(str1[i], str2[countOfLetters])) {
                countOfLetters++;
            }
        }
        return countOfLetters == str2.length();
    }
};
