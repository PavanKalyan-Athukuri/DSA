class Solution {
public:
    string getEncryptedString(string s, int k) {
        string res;
        int size = s.size();
        for(int i=0;i<s.length();i++){
            int replaceIndex = (i+k)%size;
            res = res+s[replaceIndex];
        }
        return res;
    }
};