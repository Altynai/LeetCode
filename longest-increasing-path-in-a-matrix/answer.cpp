#define NIL -1

struct Edge {
    int v, w, nxt;
};

class Solution {
private:
    int n, m, eid;
    int source, sink;
    vector<int> head;
    vector<Edge> edge;

    void addEdge(int u, int v, int w) {
        edge[eid].v = v;
        edge[eid].w = w;
        edge[eid].nxt = head[u];
        head[u] = eid++;
    }

    void buildGraph(vector<vector<int> >& matrix) {
        n = matrix.size();
        if (n == 0)
            return;
        m = matrix[0].size();
        eid = 0;
        edge = vector<Edge>(6 * n * m); // 4 directions, source, sink
        head = vector<int>(n * m + 2, NIL);
        source = n * m, sink = n * m + 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int u = i * m + j, v;
                addEdge(source, u, 1);
                addEdge(u, sink, 1);
                // above
                if (i > 0 && matrix[i][j] < matrix[i - 1][j]) {
                    v = (i - 1) * m + j;
                    addEdge(u, v, 1);
                }
                // below
                if (i + 1 < n && matrix[i][j] < matrix[i + 1][j]) {
                    v = (i + 1) * m + j;
                    addEdge(u, v, 1);
                }
                // left
                if (j > 0 && matrix[i][j] < matrix[i][j - 1]) {
                    v = i * m + j - 1;
                    addEdge(u, v, 1);
                }
                // right
                if (j + 1 < m && matrix[i][j] < matrix[i][j + 1]) {
                    v = i * m + j + 1;
                    addEdge(u, v, 1);
                }
            }
        }
    }

    int findLongestPath() {
        vector<int> distance(n * m + 2, 0);
        vector<bool> inQueue(n * m + 2, false);
        queue<int> q;
        q.push(source);
        inQueue[source] = true;
        while (!q.empty()) {
            int u = q.front();
            inQueue[u] = false;
            q.pop();
            for (int p = head[u]; p != NIL; p = edge[p].nxt) {
                int v = edge[p].v, w = edge[p].w;
                if (distance[v] < distance[u] + w) {
                    distance[v] = distance[u] + w;
                    if (!inQueue[v]) {
                        inQueue[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        return distance[sink] - 1;
    }

public:
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        buildGraph(matrix);
        if (n == 0)
            return 0;
        return findLongestPath();
    }
};
