class Solution {
public:
    void helper(string s,int index,vector<string>& res){
        if(index==s.size()){
            res.push_back(s);
            return;
        }
        if(isupper(s[index]))
        {
            s[index] = tolower(s[index]);
            helper(s,index+1,res);
            s[index] = toupper(s[index]);
        }
        if(islower(s[index]))
        {
            s[index] = toupper(s[index]);
            helper(s,index+1,res);
            s[index] = tolower(s[index]);
        }
        helper(s,index+1,res);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        helper(s,0,res);
        return res;
    }
};