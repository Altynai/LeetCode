// Forward declaration of the knows API.
bool knows(int a, int b);
// knows(a, b) => true, a can't be, b may be
// knows(a, b) => false, b can't, a may be
class Solution {
public:
    int findCelebrity(int n) {
        vector<vector<bool> > relations(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                relations[i][j] = i == j ? true : knows(i, j);
        }
        for (int i = 0; i < n; i++) {
            // row is all `false`
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (i != j && relations[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                continue;
            // column is all `true`
            for (int j = 0; j < n; j++) {
                if (i != j && !relations[j][i]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return i;
        }
        return -1;
    }
};