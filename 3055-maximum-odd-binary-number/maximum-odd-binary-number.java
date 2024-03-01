class Solution {
    public String maximumOddBinaryNumber(String s) {
        int count = 0;
        int length = s.length();
        for(int i=0;i<length;i++){
            if(s.charAt(i)=='1')
                count++;
        }
        String res = "";
        for(int i=0;i<count-1;i++){
            res = res+"1";
        }
        for(int i=0;i<length-count;i++){
            res = res+"0";
        }
        res = res+"1";
        return res;
    }
}