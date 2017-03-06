#define N 26

class Solution {
public:
    vector<vector<bool>> graph;
    vector<int> degree;
    set<int> appears;
    vector<bool> visited;

    int offset(const char& chr) {
        return (int)(chr - 'a');
    }

    bool dfs(int from) {
        visited[from] = true;
        for (int to = 0; to < N; ++to) {
            if (!graph[from][to])
                continue;
            if (visited[to])
                return true;
            if (dfs(to))
                return true;
        }
        visited[from] = false;
        return false;
    }

    bool hasCycle() {
        visited = vector<bool>(N, false);
        for (auto i = appears.begin(); i != appears.end(); ++i) {
            int from = *i;
            if (dfs(from))
                return true;
        }
        return false;
    }

    string alienOrder(vector<string>& words) {
        int n = words.size();
        if (n == 0)
            return "";

        graph = vector<vector<bool>>(N, vector<bool>(N, false));
        degree = vector<int>(N, 0);
        appears = set<int>();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < words[i].size(); ++j)
                appears.insert(offset(words[i][j]));
        }

        for (int i = 1; i < n; ++i) {
            int j = 0;
            int length = min(words[i - 1].size(), words[i].size());
            while (j < length) {
                int from = offset(words[i - 1][j]);
                int to = offset(words[i][j]);
                if (words[i - 1][j] != words[i][j]) {
                    if (!graph[from][to]) {
                        graph[from][to] = true;
                        degree[to]++;
                    }
                    break;
                }
                j++;
            }
        }

        if (hasCycle())
            return "";

        string ans = "";
        while (true) {
            int from = -1;
            for (auto i = appears.begin(); i != appears.end(); ++i) {
                if (degree[*i] == 0) {
                    from = *i;
                    break;
                }
            }
            if (from == -1)
                break;
            appears.erase(from);
            for (int to = 0; to < N; ++to) {
                if (graph[from][to])
                    degree[to]--;
            }
            ans += (char)('a' + from);
        }
        for (auto i = appears.begin(); i != appears.end(); ++i) {
            int from = *i;
            ans += (char)('a' + from);
        }
        return ans;
    }
};