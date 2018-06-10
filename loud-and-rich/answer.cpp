#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> vvi;
    vector<int> ins;
    vector<int> ans;
    vector<int> quiet;

public:
    void dfs(int u) {
        if (ans[u] != -1)
            return;
        ans[u] = u;
        for (int& v : vvi[u]) {
            dfs(v);
            if (quiet[ans[v]] < quiet[ans[u]])
                ans[u] = ans[v];
        }
    }

    vector<int> loudAndRich(vector<vector<int> >& richer, vector<int>& quiet) {
        this->quiet = quiet;
        int n = quiet.size(), m = richer.size();
        ins = vector<int>(n, 0);
        ans = vector<int>(n, -1);
        vvi = vector<vector<int>>(n, vector<int>());

        for (int i = 0; i < m; i++) {
            int u = richer[i][1];
            int v = richer[i][0];
            vvi[u].push_back(v);
            ins[v]++;
        }
        for (int i = 0; i < n; i++) {
            if (ins[i] == 0)
                dfs(i);
        }
        return ans;
    }
};
