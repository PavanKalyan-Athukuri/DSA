class Solution {
    public boolean canArrange(int[] arr, int k) {
        int length = arr.length;
        int sum = 0;
        int freq[] = new int[k+1];
        for(int num:arr){
            num = num%k;
            if(num<0)
                num = num+k;
            freq[num]++;
        }
        if(freq[0]%2!=0)
            return false;
        for(int i=1;i<=k/2;i++){
            if(freq[i]!=freq[k-i])
                return false;
        }
        return true;
    }
}