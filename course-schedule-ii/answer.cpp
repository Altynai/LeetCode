#include <vector>

using namespace std;

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
    vector<int> degree;

    void addEdge(int u, int v) {
        degree[v]++;
        edges[m].v = v;
        edges[m].nxt = head[u];
        head[u] = m++;
    }

    void init(int numCourses, vector<pair<int, int> >& prerequisites) {
        int edgeAmount = prerequisites.size();
        n = numCourses;
        m = 0;
        edges = std::vector<Edge>(edgeAmount);
        head = std::vector<int>(n, NIL);
        degree = std::vector<int>(n, 0);
        for (int i = 0; i < edgeAmount; ++i) {
            int v = prerequisites[i].first;
            int u = prerequisites[i].second;
            addEdge(u, v);
        }
    }

    vector<int> solve() {
        vector<int> answer;
        while (1) {
            int node = NIL;
            for (int i = 0; i < n; ++i) {
                if (degree[i] == 0) {
                    node = i;
                    break;
                }
            }
            if (node == NIL)
                return answer.size() == n ? answer : vector<int>();
            for (int i = head[node]; i != NIL; i = edges[i].nxt)
                degree[edges[i].v]--;
            degree[node] = NIL;
            answer.push_back(node);
        }
        return answer;
    }

public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        init(numCourses, prerequisites);
        return solve();
    }
};