class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<vector<int>> queries_index;
        for(string s:queries){
            vector<int> index_vector;
            for(int i=0;i<s.size();i++){
                index_vector.push_back((int)s[i]);
            }
            queries_index.push_back(index_vector);
        }

        vector<vector<int>> dictionary_index;
        for(string s:dictionary){
            vector<int> index_vector;
            for(int i=0;i<s.size();i++){
                index_vector.push_back((int)s[i]);
            }
            dictionary_index.push_back(index_vector);
        }
        vector<string> res;
        for(int p=0;p<queries_index.size();p++){
            int j=0;
            while(j<dictionary.size()){
                string str = dictionary[j];
                bool flag = false;
                int count=0;
                for(int i=0;i<queries_index[p].size();i++){
                    if(queries_index[p][i]!=str[i]&&count>=2){
                        flag = true;
                        break;
                    }else if(queries_index[p][i]!=str[i]&&count<2){
                        count++;
                    }
                }
                if(!flag){
                    res.push_back(queries[p]);
                    break;
                }
                j++;
            }
        }
        return res;
    }
};