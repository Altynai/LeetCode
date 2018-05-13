class Solution {
private:
    vector<char> ans;
    set<int> visited;
    int n, k, m, mod, total;

    int pow(int a, int b) {
        int ans = 1;
        for (int i = 0; i < b; i++)
            ans *= a;
        return ans;
    }

    void init(int n, int k) {
        total = pow(k, n);
        m = pow(k, n) + n - 1, mod = pow(10, n - 1);
        ans.resize(m);
        for (int i = 0; i < n - 1; i++)
            ans[i] = '0';
        visited.clear();
        this->n = n;
        this->k = k;
    }

    bool dfs(int sum, int pos) {
        if (pos == m)
            return visited.size() == total;
        for (int i = 0; i < k; i++) {
            int w = (sum % mod) * 10 + i;
            if (visited.find(w) != visited.end())
                continue;
            ans[pos] = '0' + i;
            visited.insert(w);
            if (dfs(w, pos + 1))
                return true;
            visited.erase(w);
        }
        return false;
    }

public:
    string crackSafe(int n, int k) {
        if (n == 1 && k == 1)
            return "0";
        init(n, k);
        dfs(0, n - 1);
        return string(ans.begin(), ans.end());
    }
};
