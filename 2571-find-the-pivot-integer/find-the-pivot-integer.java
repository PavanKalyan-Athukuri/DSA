class Solution {
    public int pivotInteger(int n) {
        int leftSum = 1;
        int rightSum = n;
        int leftPointer = 1;
        int rightPointer = n;
        if(n==1)
            return n;
        while(leftPointer<rightPointer){
            if(leftPointer+1==rightPointer-1&&leftSum==rightSum)
                return leftPointer+1;
            if(leftSum<rightSum)
            leftSum += ++leftPointer;
            else
            rightSum += --rightPointer;
        }
        return -1;
    }
}