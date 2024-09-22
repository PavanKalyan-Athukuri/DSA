class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        map<string,int> mymap;
        for(int i=0;i<bannedWords.size();i++){
            mymap[bannedWords[i]] = 1; 
        }
        int count = 0;
        for(int i=0;i<message.size();i++){
            if(mymap[message[i]]==1){
                count++;
            }
        }
        if(count>=2)
            return true;
        else
            return false;
    }
};