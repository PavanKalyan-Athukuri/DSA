class Solution {
    public static int arr[] = new int[46];
    public int climbStairs(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        if(arr[n]!=0)
            return arr[n];
        return arr[n] = climbStairs(n-1)+climbStairs(n-2);
    }
}