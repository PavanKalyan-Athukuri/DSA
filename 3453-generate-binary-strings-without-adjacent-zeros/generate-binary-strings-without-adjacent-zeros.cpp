class Solution {
public:
    set<string> res;
    void helper(string str,int last,int n){
        if(str.size()==n){
            res.insert(str);
            return ;
        }
        if(last){
            helper(str+"1",1,n);
                helper(str+"0",0,n);
        }
        else
            helper(str+"1",1,n);
    }
    vector<string> validStrings(int n) {
       helper("",0,n);
        helper("",1,n);
        vector<string> arr(res.begin(),res.end());
        return arr;
    }
};