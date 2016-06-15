
#define NIL -1
#define N 1000000

int cache[N] = {0};

class Solution {
private:
    int dfs(int n) {
        if (n <= 3)
            return cache[n] = n;
        if (cache[n] != 0)
            return cache[n];
        int root = (int)sqrt((double)n), answer = NIL;
        for (int i = root; i >= 1; --i) {
            int value = dfs(n - i * i);
            if (answer == NIL || value + 1 < answer)
                answer = value + 1;
        }
        return cache[n] = answer;
    }

public:
    int numSquares(int n) {
        return dfs(n);
    }
};