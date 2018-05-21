#define N 100006

class Solution {
private:
    int L[N], R[N], n;
    char state[N];

public:
    string pushDominoes(string dominoes) {
        n = dominoes.size();
        memset(L, -1, sizeof(L));
        memset(R, -1, sizeof(R));
        for (int i = 0; i < n; i++) {
            if (i == 0)
                R[0] = -1;
            else if (dominoes[i - 1] == 'R')
                R[i] = i - 1;
            else if (dominoes[i - 1] == 'L')
                R[i] = -1;
            else
                R[i] = R[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1)
                L[n - 1] = -1;
            else if (dominoes[i + 1] == 'L')
                L[i] = i + 1;
            else if (dominoes[i + 1] == 'R')
                L[i] = -1;
            else
                L[i] = L[i + 1];
        }

        for (int i = 0; i < n; i++) {
            if (dominoes[i] != '.') {
                state[i] = dominoes[i];
                continue;
            }
            int r = R[i], l = L[i];
            if (l == -1 && r == -1)
                state[i] = '.';
            else if (l == -1 && r != -1)
                state[i] = 'R';
            else if (l != -1 && r == -1)
                state[i] = 'L';
            else {
                int b = l - i, a = i - r;
                if (a == b)
                    state[i] = '.';
                else if (a < b)
                    state[i] = 'R';
                else
                    state[i] = 'L';
            }
        }
        return string(state, state + n);
    }
};
