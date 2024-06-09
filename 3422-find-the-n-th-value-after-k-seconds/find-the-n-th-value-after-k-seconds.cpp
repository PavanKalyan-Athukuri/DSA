#define MOD 1000000007
class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int> arr(n,1);
        for(int i=1;i<=k;i++){
            for(int j=1;j<n;j++){
                arr[j] = (arr[j]+arr[j-1])%MOD;
            }
        }
        return arr[n-1];
    }
};