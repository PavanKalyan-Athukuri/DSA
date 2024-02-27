class Solution {
    public long countPairs(int[] nums, int k) {
       Map<Integer,Long> map = new HashMap<>();
        long sum = 0;
        for(int i=0;i<nums.length;i++){
            int gcd = gcd(nums[i],k);
            for(Map.Entry<Integer,Long> entry:map.entrySet()){
                long num = (long)gcd*(long)entry.getKey();
                if(num%(long)k==0)
                    sum = sum+entry.getValue();
            }
            map.put(gcd,map.getOrDefault(gcd,0L)+1);
        }
        return sum;
    }    
    private int gcd(int a,int b){
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    
}