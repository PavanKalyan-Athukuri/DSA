class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        vector<int> rows(mat.size(),0);
        vector<int> cols(mat[0].size(),0);
        map<int,pair<int,int>> map;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                map[mat[i][j]] = {i,j};
            }
        }
        for(int i=0;i<arr.size();i++){
            pair<int,int> p = map[arr[i]];
            rows[p.first] +=1;
            cols[p.second] +=1;
            if(rows[p.first]==mat[0].size())
                return i;
            if(cols[p.second]==mat.size())
                return i;
        }
        return 0;
    }
};