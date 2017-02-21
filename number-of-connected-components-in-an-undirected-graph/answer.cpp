#define NIL -1

struct Edge {
    int v;
    int nxt;
};

class Solution {
private:
    int n, m;
    vector<Edge> _edges;
    vector<int> head;
    vector<bool> visited;

    void addEdge(int u, int v) {
        _edges[m].v = v;
        _edges[m].nxt = head[u];
        head[u] = m++;
    }

    void dfs(int root) {
        visited[root] = true;
        for (int i = head[root]; i != NIL; i = _edges[i].nxt) {
            int v = _edges[i].v;
            if (!visited[v])
                dfs(v);
        }
    }
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        this->n = n;
        m = 0;
        _edges.resize(edges.size() * 2);
        head = vector<int>(n, NIL);
        visited = vector<bool>(n, false);
        for (int i = 0; i < edges.size(); ++i) {
            addEdge(edges[i].first, edges[i].second);
            addEdge(edges[i].second, edges[i].first);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i);
                ans++;
            }
        }
        return ans;
    }
};