#define N 100005

struct Node {
    int d, p;
    Node(int _d, int _p): d(_d), p(_p) {}
    friend bool operator<(const Node& lh, const Node& rh) {
        if (lh.d != rh.d)
            return lh.d < rh.d;
        return lh.p > rh.p;
    }
};

int indexTree[N];

void update(int index, int profit) {
    while (index < N) {
        indexTree[index] = max(indexTree[index], profit);
        index += index & (-index);
    }
}

int get(int index) {
    int ans = 0;
    while (index >= 1) {
        ans = max(indexTree[index], ans);
        index -= index & (-index);
    }
    return ans;
}

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<Node> dps;
        for (int i = 0; i < n; i++)
            dps.push_back(Node(difficulty[i], profit[i]));
        sort(dps.begin(), dps.end());
        int j = 0, ans = 0;
        memset(indexTree, 0, sizeof(indexTree));
        for (auto work : worker) {
            while (j < n && dps[j].d <= work) {
                update(dps[j].d, dps[j].p);
                j++;
            }
            ans += get(work);
        }
        return ans;
    }
};