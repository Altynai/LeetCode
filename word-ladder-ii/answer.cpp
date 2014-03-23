
class DictUtils {
public:
    map<string, int> word2int;
    map<int, string> int2word;

    DictUtils() {
        word2int.clear();
        int2word.clear();
    }

    int getWordID(const string &word) {
        map<string, int>::iterator it = word2int.find(word);
        if (it == word2int.end()) {
            int count = word2int.size();
            word2int[word] = count;
            int2word[count] = word;
            return count;
        } else
            return it->second;
    }

    string getWord(int id) {
        map<int, string>::iterator it = int2word.find(id);
        if (it == int2word.end())
            return "";
        else
            return it->second;
    }

};

class Graph {
private:
    struct Edge {
        int v;
        Edge *next;
        Edge(int _v): v(_v), next(NULL) {}
    };

    int n; // node count
    Edge **head;
    vector<vector<int> > pre_node;
    string *path;

    void dfs(vector<vector<string> > &result, int start, int current, DictUtils *dict_utils, int count) {
        if (start == current) {
            vector<string> answer;
            for (int i = count - 1; i >= 0; i--)
                answer.push_back(path[i]);
            result.push_back(answer);
            return;
        }
        for (int i = 0; i < pre_node[current].size(); i++) {
            int node = pre_node[current][i];
            path[count] = dict_utils->getWord(node);
            dfs(result, start, node, dict_utils, count + 1);
        }
    }

public:
    static const int MAX_INT = 0x7fffffff;

    Graph(int _n) {
        n = _n;
        pre_node = vector<vector<int> >(n, vector<int>());
        head = new Edge*[n];
        for (int i = 0; i < n; i++)
            head[i] = NULL;
        path = new string[n];
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
                    pre_node[v].push_back(u);
                    distance[v] = distance[u] + 1;
                    q.push(v);
                } else {
                    if (distance[v] == distance[u] + 1)
                        pre_node[v].push_back(u);
                }
            }
        }
        return MAX_INT;
    }

    vector<vector<string> > findPaths(int start, int end, DictUtils *dict_utils) {
        vector<vector<string> > result;
        path[0] = dict_utils->getWord(end);
        dfs(result, start, end, dict_utils, 1);
        return result;
    }
};

class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        DictUtils *dict_utils = new DictUtils();
        dict.insert(start);
        dict.insert(end);
        int n = dict.size();
        int start_id = dict_utils->getWordID(start);
        int end_id = dict_utils->getWordID(end);
        Graph *graph = new Graph(n);

        for (unordered_set<string>::iterator i = dict.begin(); i != dict.end(); i++) {
            int u = dict_utils->getWordID(*i);
            string temp = *i;
            for (int j = 0; j < temp.size(); j++) {
                char old = temp[j];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == temp[j])
                        continue;
                    temp[j] = ch;
                    if (dict.find(temp) != dict.end())
                        graph->addEdge(u, dict_utils->getWordID(temp));
                    temp[j] = old;
                }
            }
        }
        int path_length = graph->bfs(start_id, end_id);
        if (path_length == Graph::MAX_INT)
            return vector<vector<string> >();
        else
            return graph->findPaths(start_id, end_id, dict_utils);
    }
};
