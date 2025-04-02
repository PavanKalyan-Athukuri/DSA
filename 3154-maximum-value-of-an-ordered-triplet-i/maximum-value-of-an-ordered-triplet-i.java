class Solution {
    public long maximumTripletValue(int[] nums) {
        int length = nums.length;
        long max = Long.MIN_VALUE;
        for(int i=0;i<length;i++){
            for(int j=i+1;j<length;j++){
                for(int k=j+1;k<length;k++){
                    max = Math.max(max,(long)(nums[i]-nums[j])*(long)nums[k]);
                }
            }
        }
        return max<0?0:max;
    }
}