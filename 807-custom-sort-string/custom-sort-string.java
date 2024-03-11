class Solution {
    public String customSortString(String order, String s) {
        char arr[] = new char[27];
        for(char ch:s.toCharArray()){
            arr[ch-97]++;
        }
        String res = "";
        for(char ch:order.toCharArray()){
            if(arr[ch-97]>0){
                while(arr[ch-97]>0){
                res = res+ch;
                arr[ch-97]--;}
            }
        }
        for(int i=0;i<27;i++){
            if(arr[i]>0){
                while(arr[i]>0){
                    res = res+(char)(i+97);
                    arr[i]--;
                }
            }
        }
        return res;
    }
}