
class SPFA {
private:
    struct Edge {
        int weight;
        int v;
        Edge *next;

        Edge(int _v, int _weight): v(_v), weight(_weight), next(NULL) {}
    };

    int n; // node count
    Edge **head;

public:
    static const int MAX_INT = 0x7fffffff;

    SPFA(int _n) {
        n = _n;
        head = new Edge*[n];
        for (int i = 0; i < n; i++)
            head[i] = NULL;
    }

    int addEdge(int u, int v, int weight) {
        Edge *edge = new Edge(v, weight);
        edge->next = head[u];
        head[u] = edge;
    }

    int shortestPath(int start, int end) {
        if (start == end)
            return 0;
        int *distance = new int[n];
        bool *in_queue = new bool[n];
        for (int i = 0; i < n; i++) {
            distance[i] = MAX_INT;
            in_queue[i] = false;
        }
        queue<int> q;
        q.push(start);
        in_queue[start] = true;
        distance[start] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_queue[u] = false;
            for (Edge *edge = head[u]; edge; edge = edge->next) {
                int v = edge->v, weight = edge->weight;
                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    if (!in_queue[v]) {
                        in_queue[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        int result = distance[end];
        delete [] in_queue;
        delete [] distance;
        return result;
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

    int diff(const string &lh, const string &rh) {
        int result = 0, n = lh.size();
        for (int i = 0; i < n; i++) {
            if (lh[i] != rh[i])
                result++;
        }
        return result;
    }

public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        map<string, int> hash;
        int start_id = getWordID(hash, start);
        int end_id = getWordID(hash, end);
        int n = 2 + dict.size();
        SPFA *spfa = new SPFA(n);

        for (unordered_set<string>::iterator i = dict.begin(); i != dict.end(); i++) {
            unordered_set<string>::iterator j = i;
            int u = getWordID(hash, *i), v = 0;
            for (j++; j != dict.end(); j++) {
                v = getWordID(hash, *j);
                if (diff(*i, *j) == 1)
                    spfa->addEdge(u, v, 1);
            }
            // add edge from `start` to `word`
            if (diff(start, *i) == 1)
                spfa->addEdge(start_id, u, 1);
            // add edge from `word` to `end`
            if (diff(end, *i) == 1)
                spfa->addEdge(u, end_id, 1);
        }
        int result = spfa->shortestPath(start_id, end_id);
        if (result == SPFA::MAX_INT)
            result = 0;
        return result;
    }
};
