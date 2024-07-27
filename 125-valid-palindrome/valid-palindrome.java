class Solution {
    public boolean isPalindrome(String s) {
        boolean res = true;
        String temp="";
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)>=65&&s.charAt(i)<=90){
                temp = temp+(char)(s.charAt(i)+32);
            }
            else if(s.charAt(i)>=97&&s.charAt(i)<=122||s.charAt(i)-'0'>=0&&s.charAt(i)-'0'<=9){
                temp = temp+s.charAt(i);
            }
        }
        for(int i=0;i<temp.length()/2;i++){
            if(temp.charAt(i)!=temp.charAt(temp.length()-i-1))
                return false;
        }
        return res;
    }
}