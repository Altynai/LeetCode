class Solution {
public:
    int numSpecial(vector < vector < int >> & a) {
        int n = a.size(), m = a[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) continue;
                int cnt = 0;
                for (int k = 0; k < m; k++)
                    if (j != k && a[i][k]) cnt++;
                for (int k = 0; k < n; k++)
                    if (i != k && a[k][j]) cnt++;
                if (cnt == 0)
                    ans++;
            }
        }
        return ans;
    }
};
