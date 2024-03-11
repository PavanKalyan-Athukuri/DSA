class Solution {
    private void backTrack(List<String> res,int n,int open,int close,String str){
        if(open==close&&open==n){
            res.add(str);
        }
        if(open>n||close>n)
            return ;
        backTrack(res,n,open+1,close,str+"(");
        if(open>close)
            backTrack(res,n,open,close+1,str+")");
    }
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        backTrack(res,n,0,0,"");
        return res;
    }
}