class Solution {
public:
    bool isPossible(vector<int>& target) {
        multiset<int64_t> ms(target.begin(), target.end());
        int n = target.size();
        int64_t sum = 0;
        for (int i = 0; i < n;i++)
            sum += target[i];

        int64_t largest = 0;
        while ((largest = *ms.rbegin()) > 1) {
            int64_t others = sum - largest;
            int64_t value = largest - others;
            if (value < 1)
                return false;
            sum -= others;
            ms.erase(largest);
            ms.insert(value);
        }
        return true;
    }
};
