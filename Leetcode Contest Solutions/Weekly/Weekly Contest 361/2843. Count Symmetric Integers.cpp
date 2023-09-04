class Solution {
public:
 bool isSymmetric(int number) {
    string numStr = to_string(number);
    int length = numStr.length();

    if (length % 2 == 1) {
        return false; // Odd-length numbers are not symmetric
    }

    int firstHalfSum = 0, secondHalfSum = 0;
    for (int i = 0; i < length / 2; i++) {
        firstHalfSum += (numStr[i] - '0');
        secondHalfSum += (numStr[length - i - 1] - '0');
    }

    return firstHalfSum == secondHalfSum;
}
    
    int countSymmetricIntegers(int low, int high) {
         int count = 0;
    for (int num = low; num <= high; num++) {
        if (isSymmetric(num)) {
            count++;
        }
    }
    return count;
    }
    
};
