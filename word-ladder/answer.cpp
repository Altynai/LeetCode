
class Graph {
private:
    struct Edge {
        int v;
        Edge *next;
        Edge(int _v): v(_v), next(NULL) {}
    };

    int n; // node count
    Edge **head;

public:
    static const int MAX_INT = 0x7fffffff;

    Graph(int _n) {
        n = _n;
        head = new Edge*[n];
        for (int i = 0; i < n; i++)
            head[i] = NULL;
    }

    int addEdge(int u, int v) {
        Edge *edge = new Edge(v);
        edge->next = head[u];
        head[u] = edge;
    }

    int bfs(int start, int end) {
        if (start == end)
            return 0;
        int *distance = new int[n];
        bool *visited = new bool[n];
        for (int i = 0; i < n; i++) {
            distance[i] = 0;
            visited[i] = false;
        }
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == end)
                return distance[u];
            for (Edge *edge = head[u]; edge; edge = edge->next) {
                int v = edge->v;
                if (!visited[v]) {
                    visited[v] = true;
                    distance[v] = distance[u] + 1;
                    q.push(v);
                }
            }
        }
        return MAX_INT;
    }
};


class Solution {
private:
    int getWordID(map<string, int> &hash, const string &word) {
        map<string, int>::iterator it = hash.find(word);
        if (it == hash.end()) {
            int count = hash.size();
            hash[word] = count;
            return count;
        } else
            return it->second;
    }

public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        map<string, int> hash;
        dict.insert(start);
        dict.insert(end);
        int n = dict.size();
        int start_id = getWordID(hash, start);
        int end_id = getWordID(hash, end);
        Graph *graph = new Graph(n);

        for (unordered_set<string>::iterator i = dict.begin(); i != dict.end(); i++) {
            int u = getWordID(hash, *i), v = 0;
            string temp = *i;
            for (int j = 0; j < temp.size(); j++) {
                char old = temp[j];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == temp[j])
                        continue;
                    temp[j] = ch;
                    if (dict.find(temp) != dict.end())
                        graph->addEdge(u, getWordID(hash, temp));
                    temp[j] = old;
                }
            }
        }
        int result = graph->bfs(start_id, end_id);
        if (result == Graph::MAX_INT)
            return 0;
        else
            return result + 1;
    }
};