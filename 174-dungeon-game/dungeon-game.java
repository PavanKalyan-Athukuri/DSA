class Solution {
    public int helper(int dungeon[][],int row,int col,int dp[][]){
        if(row==dungeon.length-1&&col==dungeon[0].length-1)
            return dungeon[row][col]<=0?-dungeon[row][col]+1:1;
        if(row<0||col<0||row>=dungeon.length||col>=dungeon[0].length)
            return (int)1e8;
        if(dp[row][col]!=0)
            return dp[row][col];
        int down = helper(dungeon,row+1,col,dp);
        int right = helper(dungeon,row,col+1,dp);
        int result = Math.min(down,right)-dungeon[row][col];
        return dp[row][col] = result<=0?1:result;
        
    }
    public int calculateMinimumHP(int[][] dungeon) {
        int dp[][] = new int[dungeon.length][dungeon[0].length];
        int res = helper(dungeon,0,0,dp);
        return res;
    }
}