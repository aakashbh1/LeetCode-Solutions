class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
       vector<int> ageCount(121, 0); // Initialize ageCount array with 121 elements, all set to 0
    int result = 0;
    
    // Count the frequency of each age
    for (int age : ages)
        ageCount[age]++;
    
    for (int ageA = 1; ageA <= 120; ageA++) {
        for (int ageB = 0.5 * ageA + 8; ageB <= ageA; ageB++) {
            if (ageCount[ageB]) {
                result += ageCount[ageA] * (ageCount[ageB] - (ageA == ageB ? 1 : 0)); 
            }
        }
    }
    
    return result;
    }
};
