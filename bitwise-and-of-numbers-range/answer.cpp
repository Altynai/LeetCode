#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
    int count(int n, int bit) {
        if (n < (1 << bit))
            return 0;
        int answer = 0;
        for (int i = 30; i >= 0; i--) {
            if (i == bit) {
                if ((n & (1 << i)) == 0)
                    break;
                else
                    continue;
            } else if ((n & (1 << i)) == 0)
                continue;
            else if (i > bit)
                answer += 1 << (i - 1);
            else
                answer += 1 << i;
        }
        if (n & (1 << bit))
            answer++;
        return answer;
    }

public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0)
            return 0;
        int answer = 0;
        for (int bit = 30; bit >= 0; --bit) {
            if (count(n, bit) - count(m - 1, bit) == n - m + 1)
                answer |= 1 << bit;
        }
        return answer;
    }
};

int main(int argc, char const *argv[]) {
    Solution* s = new Solution();
    assert(s->count(7, 2) == 4);
    assert(s->count(4, 2) == 1);
    assert(s->count(7, 1) == 4);
    assert(s->count(4, 1) == 2);
    assert(s->count(7, 0) == 4);
    assert(s->count(4, 0) == 2);
    assert(s->count(4, 1) == 2);
    assert(s->rangeBitwiseAnd(5, 7) == 4);
    return 0;
}