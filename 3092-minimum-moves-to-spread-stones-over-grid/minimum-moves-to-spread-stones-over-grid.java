class Pair{
    int x;
    int y;
    Pair(int x,int y){
        this.x = x;
        this.y = y;
    }
}
class Solution {
    public int helper(int grid[][],List<Pair> zeroes,List<Pair> extras,int currIndex){
        if(currIndex==zeroes.size())
        return 0;
        int min = (int)1e6;
        int zeroX = zeroes.get(currIndex).x;
        int zeroY = zeroes.get(currIndex).y;
        for(int i=0;i<extras.size();i++){
            int extraX = extras.get(i).x;
            int extraY = extras.get(i).y;
            if(grid[extraX][extraY]>1){
            int manhatten = Math.abs(zeroX-extraX)+Math.abs(zeroY-extraY);
            grid[extraX][extraY]--;
            grid[zeroX][zeroY]++;
            min = Math.min(min,manhatten+helper(grid,zeroes,extras,currIndex+1));
            grid[extraX][extraY]++;
            grid[zeroX][zeroY]--;
        }
        }
        return min;
    }
    public int minimumMoves(int[][] grid) {
        List<Pair> zeroes = new ArrayList<>();
        List<Pair> extras = new ArrayList<>();
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==0)
                zeroes.add(new Pair(i,j));
                if(grid[i][j]>1)
                extras.add(new Pair(i,j));
            }
        }
        return helper(grid,zeroes,extras,0);
    }
}