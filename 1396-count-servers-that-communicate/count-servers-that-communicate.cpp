class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> rows(grid.size(),0);
        vector<int> cols(grid[0].size(),0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    rows[i] += 1;
                    cols[j] += 1;
                }
            }
        }
        int result = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]&&(rows[i]>1||cols[j]>1))
                    result++;
            }
        }
        return result;
    }
};