class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        vector<double> diagonals;
        int area=0;
        double max1 = -1.0;
        for(int i=0;i<dimensions.size();i++){
            int length = dimensions[i][0];
            int width = dimensions[i][1];
            double diagonal = sqrt((length*length)+(width*width));
            if(diagonal>max1){
                max1 = diagonal;
                area = length*width;
            }
            else if(diagonal==max1){
                area = max(area,length*width);
            }
        }
        return area;
    }
};