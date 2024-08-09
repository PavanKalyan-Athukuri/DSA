class Solution {
    public int trap(int[] height) {
        int leftMax[] = new int[height.length];
        int rightMax[] = new int[height.length];
        int res[] = new int[height.length];
        leftMax[0] = height[0];
        rightMax[height.length-1] = height[height.length-1];
        int max = height[0];
        for(int i=0;i<height.length;i++){
            max = Math.max(height[i],max);
            leftMax[i] = max;
        }
        max = height[height.length-1];
        for(int i=height.length-1;i>=0;i--){
            max = Math.max(height[i],max);
            rightMax[i] = max;
        }
        for(int i=0;i<height.length;i++){
            res[i] = Math.min(leftMax[i],rightMax[i]);
        }
        int ans = 0;
        for(int i=0;i<height.length;i++){
            ans = ans+Math.abs(height[i]-res[i]);
        }
        return ans;
    }
}