class Solution {
    vector<vector<string>> result;
    private: void save(vector<vector<char>> &arr,int n){
        vector<string> vec;
        for(int i=0;i<n;i++){
            string str = string(arr[i].begin(),arr[i].end());
            vec.push_back(str);
        }
        result.push_back(vec);
    }
public:
    void solve(vector<vector<char>> &arr,int n,int i){
        if(i==n)
            save(arr,n);
        for(int col=0;col<n;col++){
            if(isValid(arr,i,col,n)){
                arr[i][col] = 'Q';
                solve(arr,n,i+1);
                arr[i][col] = '.';
            }
        }
        
    }
    bool isValid(vector<vector<char>> &board,int row,int col,int n){
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> arr(n,vector<char>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j] = '.';
            }
        }
        solve(arr,n,0);
        return result;
    }
};