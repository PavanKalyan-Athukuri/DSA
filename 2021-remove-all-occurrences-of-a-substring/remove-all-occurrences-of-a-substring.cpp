class Solution {
public:
    string removeOccurrences(string s, string part) {
        int second = part.length();
        size_t pos;
        while((pos=s.find(part))!=string::npos){
            s.erase(pos,second);
        }
        return s;
    }
};