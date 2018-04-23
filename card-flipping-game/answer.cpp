class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        vector<int> concat(fronts.begin(), fronts.end());
        concat.insert(concat.end(), backs.begin(), backs.end());
        sort(concat.begin(), concat.end());
        auto last = unique(concat.begin(), concat.end());
        concat.erase(last, concat.end());
        for (auto value : concat) {
            bool valid = true;
            for (int i = 0; i < fronts.size(); i++) {
                if (fronts[i] != value && backs[i] != value)
                    continue;
                if (fronts[i] == value && backs[i] == value) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                return value;
        }
        return 0;
    }
};