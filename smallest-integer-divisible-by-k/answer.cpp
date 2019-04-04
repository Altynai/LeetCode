class Solution {
public:
    int smallestRepunitDivByK(int K) {
        unordered_set<int> seen;
        int len = 0, cur = 0;
        while (true) {
            cur = (cur * 10 + 1) % K;
            len++;
            if (cur == 0)
                return len;
            else if (seen.find(cur) != seen.end())
                break;
            seen.insert(cur);
        }
        return -1;
    }
};
