#define N 1
#define i64 long long
#define PII pair<int, int>
#define MP(a, b) make_pair((a), (b))
#define FOR(i, s, t) for (int i = (s); i < (t); i++)
#define DFOR(i, s, t) for (int i = (s); i > (t); i--)
#define FILL(a, b) memset(a, b, sizeof(a))
#define PRINTVEC(v) std::copy(begin((v)), end((v)),std::ostream_iterator<int>(std::cout, " " )), cout << endl;

const i64 MOD = 1000000000 + 7;

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        multiset<int> pos, neg;
        int zero = 0;
        
        FOR(i, 0, A.size()) {
            if (A[i] == 0)
                zero++;
            else if (A[i] > 0)
                pos.insert(A[i]);
            else
                neg.insert(A[i]);
        }
        
        if (zero % 2 == 1 || pos.size() % 2 == 1 || neg.size() % 2 == 1)
            return false;

        while (!pos.empty()) {
            int x = *pos.begin();
            auto it = pos.find(x * 2);
            if (it == pos.end())
                return false;
            pos.erase(it);
            pos.erase(pos.begin());
        }

        while (!neg.empty()) {
            int x = *neg.begin();
            auto it = neg.find(x / 2);
            if (it == neg.end())
                return false;
            neg.erase(it);
            neg.erase(neg.begin());
        }
        
        return true;
    }
};
