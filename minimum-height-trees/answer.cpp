#define NIL -1

struct Edge {
    int u;
    int v;
    int weight;
    int nxt;
};

class Solution {
private:
    int n, m;
    vector<Edge> edge;
    vector<int> head;

    void init(int n, vector<pair<int, int> >& edges) {
        assert(edges.size() == n - 1);
        this->n = n;
        m = 0;
        head = vector<int>(n, NIL);
        edge = vector<Edge>((n - 1) * 2);
        for (int i = 0; i < n - 1; ++i) {
            pair<int, int> road = edges[i];
            addEdge(road.first, road.second);
            addEdge(road.second, road.first);
        }
    }

    void addEdge(int u, int v) {
        edge[m].u = u;
        edge[m].v = v;
        edge[m].weight = NIL;
        edge[m].nxt = head[u];
        head[u] = m++;
    }

    int dfs(Edge& road) {
        if (road.weight != NIL)
            return road.weight;
        int u = road.u, v = road.v, weight = 0;
        for (int idx = head[v]; idx != NIL; idx = edge[idx].nxt) {
            Edge& e = edge[idx];
            if (e.v == u)
                continue;
            weight = max(dfs(e), weight);
        }
        return road.weight = weight + 1;
    }

    vector<int> solve() {
        for (int i = 0; i < m; ++i) {
            Edge& road = edge[i];
            if (road.weight == NIL)
                dfs(road);
        }
        vector<int> mht(n, 0);
        int height = NIL;
        for (int u = 0; u < n; ++u) {
            for (int idx = head[u]; idx != NIL; idx = edge[idx].nxt)
                mht[u] = max(mht[u], edge[idx].weight);
            if (height == NIL || mht[u] < height)
                height = mht[u];
        }
        vector<int> answer;
        for (int u = 0; u < n; ++u) {
            if (mht[u] == height)
                answer.push_back(u);
        }
        return answer;
    }

public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
        init(n, edges);
        return solve();
    }
};