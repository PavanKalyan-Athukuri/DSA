class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> decoded(encoded.size()+1);
        decoded[0] = first;
        for(int i=0;i<encoded.size();i++){
            int last = decoded[i];
            int res = last^encoded[i];
            //cout << res <<" "<<encoded[i]<<"\n";
            decoded[i+1] = res;
        }
        return decoded;
    }
};