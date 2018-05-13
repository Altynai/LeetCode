#define NN 10005

struct Node {
    int u, v, nxt, count, sum;
} nodes[NN << 1];
int head[NN], n, m;

class Solution {
private:
    void init(int N, vector<vector<int>>& edges) {
        n = N;
        m = 0;
        memset(head, -1, sizeof(head));
        for (vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            add(u, v);
            add(v, u);
        }
    }

    void add(int u, int v) {
        nodes[m].u = u;
        nodes[m].v = v;
        nodes[m].count = -1;
        nodes[m].sum = -1;
        nodes[m].nxt = head[u];
        head[u] = m++;
    }

    void dfs(int i) {
        if (nodes[i].count != -1)
            return;
        int u = nodes[i].u, v = nodes[i].v;
        // u--->v--->w
        // |.i..|..p.|
        int sum = 0, count = 1;
        for (int p = head[v]; p != -1; p = nodes[p].nxt) {
            int w = nodes[p].v;
            if (w == u)
                continue;
            dfs(p);
            count += nodes[p].count;
            sum += nodes[p].sum + nodes[p].count;
        }
        nodes[i].count = count;
        nodes[i].sum = sum;
    }

    vector<int> solve() {
        vector<int> ans(n);
        // u--->v
        // |.i..|
        for (int i = 0; i < m; i++) {
            int u = nodes[i].u, v = nodes[i].v;
            ans[u] += nodes[i].sum;
            ans[u] += nodes[i].count;
        }
        return ans;
    }

public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        init(N, edges);
        for (int i = 0; i < m; i++) {
            if (nodes[i].count == -1)
                dfs(i);
        }
        return solve();
    }
};
