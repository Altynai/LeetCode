const int N = 5;
const int DENOS[N] = {20, 50, 100, 200, 500};

class ATM {
private:
  vector<long long> cnt;

public:
  ATM() { cnt = vector<long long>(N, 0); }

  void deposit(vector<int> banknotesCount) {
    for (int i = 0; i < N; i++)
      cnt[i] += banknotesCount[i];
  }

  vector<int> withdraw(int amount) {
    vector<int> ans(N, 0);
    for (int i = 0; i < 2; i++) {
      long long m = amount;
      for (int j = N - 1; j >= 0; j--) {
        long long d = min(cnt[j], m / DENOS[j]);
        m -= d * DENOS[j];

        if (i) {
          ans[j] += d;
          cnt[j] -= d;
        }
      }
      if (i == 0 and m > 0)
        return {-1};
    }
    return ans;
  }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
