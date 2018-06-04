class Solution {
private:
    auto next(map<int, int>& counter, auto it) {
        if (it->second == 1)
            return counter.erase(it);
        else {
            it->second -= 1;
            it++;
            return it;
        }
    }

public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if (n % W != 0)
            return false;
        map<int, int> counter;
        for (int& card : hand)
            counter[card]++;

        int loop = n / W;
        for (int i = 0; i < loop; i++) {
            auto it = counter.begin();
            int value = it->first + 1;
            it = next(counter, it);
            for (int j = 0; j < W - 1; j++) {
                if (it == counter.end())
                    return false;
                if (it->first != value)
                    return false;
                it = next(counter, it);
                value++;
            }
        }
        return counter.empty();
    }
};
