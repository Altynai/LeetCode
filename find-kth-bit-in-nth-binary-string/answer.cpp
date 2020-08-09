class Solution {
public:
    int dfs(int n, int k) {
        if (n == 1) return 0;
        
        int mid = 1 << (n - 1);
        if (k == mid) return 1;
        else if (k < mid) return dfs(n - 1, k);
        else {
            k -= mid;
            int k2 = (1 << (n - 1)) - k;
            return dfs(n - 1, k2) ^ 1;
        }
    }

    char findKthBit(int n, int k) {
        return '0' + dfs(n, k);
    }
};
