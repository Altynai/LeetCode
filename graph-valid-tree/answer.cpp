#define NIL -1

struct Edge {
    int v;
    int nxt;
};

class Solution {
private:
    int n, m;
    vector<Edge> edges;
    vector<int> head;
    vector<bool> visited;

    void addEdge(int u, int v) {
        edges[m].v = v;
        edges[m].nxt = head[u];
        head[u] = m++;
    }

    void init(int n, vector<pair<int, int>>& pairs) {
        this->n = n;
        m = 0;
        edges = vector<Edge>(pairs.size() * 2);
        head = vector<int>(n, NIL);
        visited = vector<bool>(n, false);
        for (int i = 0; i < pairs.size(); ++i) {
            int u = pairs[i].first;
            int v = pairs[i].second;
            addEdge(u, v);
            addEdge(v, u);
        }
    }

    bool dfs(int u, int parent) {
        visited[u] = true;
        for (int i = head[u]; i != NIL; i = edges[i].nxt) {
            int v = edges[i].v;
            if (v == parent)
                continue;
            else if (!visited[v]) {
                if (!dfs(v, u))
                    return false;
            } else
                return false;
        }
        return true;
    }

public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n - 1)
            return false;
        init(n, edges);
        if (!dfs(0, -1))
            return false;
        for (int i = 0; i < n; ++i) {
            if (!visited[i])
                return false;
        }
        return true;
    }
};