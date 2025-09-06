class Solution {
    using ll = long long;
public:
    ll get(int num){
        int i=1;
        int base =1;
        ll cnt = 0;
        while(base<=num){
            cnt += 1ll*(i+1)/2*(min(base*2-1,num)-base+1);
            i++;
            base = base*2;
        }
        return cnt;
    }
    long long minOperations(vector<vector<int>>& queries) {
        ll res = 0;
        for(int i=0;i<queries.size();i++){
            int left = queries[i][0];
            int right = queries[i][1];
            res += (get(right)-get(left-1)+1)/2;
        }
        return res;
    }
};