class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>0){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        int maxi = INT_MIN;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            queue<pair<int,int>> t_queue;
            if(!visited[p.first][p.second])
                t_queue.push(p);
            int sum = 0;
            while(!t_queue.empty()){
                p = t_queue.front();
                t_queue.pop();
                int row = p.first;
                int col = p.second;
                sum = sum+grid[row][col];
                visited[row][col] = 1;
                for(int i=0;i<4;i++){
                    int row1 = row+dx[i];
                    int col1 = col+dy[i];
                    if(row1<0||col1<0||row1>=grid.size()||col1>=grid[0].size()||grid[row1][col1]==0){
                        continue;
                    }
                    if(!visited[row1][col1]){
                        visited[row1][col1] = 1;
                        t_queue.push({row1,col1});
                    }
                }
            }
            maxi = max(maxi,sum);
        }
        return maxi==INT_MIN?0:maxi;
    }
};