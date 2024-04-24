class Solution {
    public int tribonacci(int n) {
        if(n==0)
        return 0;
        if(n==1)
        return 1;
        if(n==2)
        return 1;
        int prev2 = 0;
        int prev = 1;
        int curr = 1;
        int temp = 0;
        for(int i=3;i<=n;i++){
            temp = curr+prev+prev2;
            prev2 = prev;
            prev = curr;
            curr = temp;
        }
        return curr;
    }
}