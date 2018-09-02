#define N 10000

class Solution {
private:
    bool vis[N];
    unordered_set<int> cycle;
    vector<vector<int>> graph;
    int n;
    bool inStk[N];
    int stk[N];

    void init(vector<vector<int>>& graph) {
        memset(vis, false, sizeof(vis));
        n = graph.size();
        this->graph = graph;
        cycle.clear();
    }

    void dfs(int u, int top) {
        vis[u] = inStk[u] = true;
        stk[top++] = u;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (inStk[v] || cycle.find(v) != cycle.end()) {
                for (int j = 0; j < top; j++)
                    cycle.insert(stk[j]);
            } else if (!vis[v])
                dfs(v, top);
        }
        inStk[u] = false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        init(graph);
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                dfs(i, 0);
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (cycle.find(i) == cycle.end())
                ans.push_back(i);
        }
        return ans;
    }
};
