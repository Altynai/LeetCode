class Bank {
private:
  vector<long long> b;
  int n;

  inline bool isValidAccount(int account) {
    return 1 <= account && account <= n;
  }

public:
  Bank(vector<long long> &balance) {
    b = balance;
    n = balance.size();
  }

  bool transfer(int x, int y, long long money) {
    if (!isValidAccount(x) || !isValidAccount(y))
      return 0;

    x--, y--;
    if (money > b[x])
      return 0;
    b[x] -= money;
    b[y] += money;
    return 1;
  }

  bool deposit(int x, long long money) {
    if (!isValidAccount(x))
      return 0;
    x--;
    b[x] += money;
    return 1;
  }

  bool withdraw(int x, long long money) {
    if (!isValidAccount(x))
      return 0;
    x--;
    if (money > b[x])
      return 0;
    b[x] -= money;
    return 1;
  }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
