class Solution {

int dp[500][500][2];

int mod = 1e+9+7;
public:
    int solve(int zero,int one,bool flag,int limit){
        if(zero==0&&one==0){
            return 1;
        }
        int ans = 0;
        if(dp[zero][one][flag]!=-1)
            return dp[zero][one][flag];
        if(flag){
            for(int i=1;i<=min(limit,one);i++){
                ans = (ans+solve(zero,one-i,false,limit)%mod)%mod;
            }
        }
        else if(!flag){
            for(int i=1;i<=min(limit,zero);i++){
                ans = (ans+solve(zero-i,one,true,limit)%mod)%mod;
            }
        }
        return dp[zero][one][flag] = (ans%mod);
    }
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        int a = solve(zero,one,true,limit);
        int b = solve(zero,one,false,limit);
        return (a+b)%mod;
    }
};