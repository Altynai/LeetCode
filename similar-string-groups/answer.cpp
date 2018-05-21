#define N 2005

class Solution {
private:
    int pre[N], n;
    int diff[2];

    int findRoot(int i) {
        int j = i, root = i;
        while(pre[root] != root)
            root = pre[root];
        while(j != root) {
            int x = pre[j];
            pre[j] = root;
            j = x;
        }
        return root;
    }

    bool swaped(const string& a, const string& b) {
        int m = 0, sz = a.size();
        for (int i = 0; i < sz; i++) {
            if (a[i] == b[i])
                continue;
            if (m == 2)
                return false;
            diff[m++] = i;
        }
        int p1 = diff[0], p2 = diff[1];
        return a[p1] == b[p2] && a[p2] == b[p1];
    }

public:
    int numSimilarGroups(vector<string>& A) {
        n = A.size();
        for (int i = 0; i < n; i++)
            pre[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int jroot = findRoot(j), iroot = findRoot(i);
                if (jroot == iroot)
                    continue;
                if (swaped(A[j], A[i]))
                    pre[jroot] = iroot;
            }
        }
        set<int> ans;
        for (int i = 0; i < n; i++)
            ans.insert(findRoot(i));
        return ans.size();
    }
};
