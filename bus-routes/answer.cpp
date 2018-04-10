#define N 505

int way[N][N], dist[N], n;
bool inQueue[N];

class Solution {
private:
    map<int, vector<int> > hash;
    int n;

    void init(vector<vector<int>>& routes, int S, int T) {
        n = routes.size();
        memset(way, -1, sizeof(way));
        hash.clear();

        for (int i = 1; i <= routes.size(); i++) {
            for (auto num : routes[i - 1])
                hash[num].push_back(i);
        }
        for (auto& kv : hash) {
            vector<int>& nums = kv.second;
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = i + 1; j < nums.size(); ++j) {
                    insert(nums[i], nums[j], 1);
                    insert(nums[j], nums[i], 1);
                }
            }
        }
        for (auto num : hash[S])
            insert(0, num, 0);
        for (auto num : hash[T])
            insert(num, n + 1, 0);
    }

    void insert(int from, int to_, int weight_) {
        way[from][to_] = weight_;
    }

    int spfa(int source, int sink) {
        memset(dist, -1, sizeof(dist));
        memset(inQueue, false, sizeof(inQueue));

        queue<int> que;
        dist[source] = 0;
        que.push(source);
        inQueue[source] = true;

        while (!que.empty()) {
            int from = que.front();
            que.pop();
            inQueue[from] = false;
            for (int to_ = 0; to_ <= n + 1; to_++) {
                if (way[from][to_] == -1)
                    continue;
                if (dist[to_] == -1 || dist[to_] > dist[from] + way[from][to_]) {
                    dist[to_] = dist[from] + way[from][to_];
                    if (!inQueue[to_]) {
                        que.push(to_);
                        inQueue[to_] = true;
                    }
                }
            }
        }
        return dist[sink] == -1 ? -1 : dist[sink] + 1;
    }

public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T)
            return 0;
        init(routes, S, T);
        return spfa(0, n + 1);
    }
};