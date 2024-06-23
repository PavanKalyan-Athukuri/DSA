class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int leftCol=1001;
        int rightCol=0;
        int topRow = 0;
        int bottomRow=1001;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    leftCol = min(leftCol,j);
                    rightCol = max(rightCol,j);
                    topRow = max(topRow,i);
                    bottomRow = min(bottomRow,i);
                }
            }
        }
        int diff1 = (rightCol-leftCol);
        int diff2 = (topRow-bottomRow);
        return((diff1+1)*(diff2+1));
    }
};