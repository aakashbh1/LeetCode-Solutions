class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int noOfL=0;
        int noOfR=0;
        int space=0;
        for(int i=0;i<moves.length();i++){
            if(moves[i]=='L') noOfL++;
            if(moves[i]=='R') noOfR++;
            if(moves[i]=='_') space++;
        }
        
        return space+abs(noOfL-noOfR);
    }
};
