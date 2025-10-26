class Bank {
public:
    vector<long long>& balance;
    int size;
    Bank(vector<long long>& b) : balance(b), size(b.size()) {}

    
    bool transfer(int account1, int account2, long long money) {
        int account1Index = account1-1;
        int account2Index = account2-1;
        if(account1Index>=0&&account1Index<size&&account2Index>=0&&account2Index<size){
            long long account1Balance = balance[account1Index];
            long long account2Balance = balance[account2Index];
            if(account1Balance-money>=0){
                balance[account2Index] += money;
                balance[account1Index] -= money;
                return true;
            }
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account-1>=0&&account-1<size){
            balance[account-1] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(account-1>=0&&account-1<size&&balance[account-1]-money>=0){
            balance[account-1] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */