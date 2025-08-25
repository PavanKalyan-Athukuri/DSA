class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row=0;
        int column=0;
        int n = mat.size();
        int m = mat[0].size();
        vector<int> res;
        bool flag=true;
        bool first = true;
        while(row>=0&&row<n&&column>=0&&column<m){
            res.push_back(mat[row][column]);
            if(flag){
                if(row==0 && column<m-1) {
                   column++;
                   flag=!flag;
                } else if(column== m-1) {
                    row++;
                    flag= !flag;
                } else {
                    row--;
                    column++;
                }
            }
            else{
                if(row<n-1 && column==0) {
                    row++;
                    flag=!flag;
                } else if(row == n -1) {
                    column++;
                    flag = !flag;
                } else {
                    row++;
                    column--;
                }
            }
        }
        return res;
    }
};