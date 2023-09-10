class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> res = new ArrayList<>();
        for(int i=1;i<10;i++){
            dfs(i,res,n);
        }
        return res;
    }
    public void dfs(int curr,List<Integer> res,int n){
        if(curr>n)
        return;
        res.add(curr);
        for(int i=0;i<10;i++){
            if(10*curr+i>n)
            return;
            dfs(10*curr+i,res,n);
        }
    }
}