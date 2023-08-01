class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
          
        int n=coordinates.size();
          int x=coordinates[0][0]-coordinates[1][0];
          int y=coordinates[0][1]-coordinates[1][1];
         
          for(int i=2;i<n;i++)
          {
              int x1= coordinates[0][0]-coordinates[i][0];
              int y1=coordinates[0][1]-coordinates[i][1];

              if(x*y1!=y*x1)
              return false;
          }

          return true;


        
    }
};
