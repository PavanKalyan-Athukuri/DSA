class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int size = bank.size();
        int prev=0;
        int res = 0;
        for(int i=size-1;i>=0;i--){
            string str = bank[i];
            int count=0;
            for(int j=0;j<str.size();j++){
                if(str[j]=='1'){
                    count++;
                }
            }
            if(count>0){
                res += prev*count;
                prev = count;
            }
        }
        return res;
    }
};