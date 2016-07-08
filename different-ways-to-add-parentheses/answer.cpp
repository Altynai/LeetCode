class Solution {
private:
    string input;
    int n;

    vector<int> compute(int l, int r) {
        vector<int> ret;
        if (l > r)
            return ret;
        for (int i = l; i <= r; ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> lh = compute(l, i - 1);
                vector<int> rh = compute(i + 1, r);
                for (int j = 0; j < lh.size(); ++j) {
                    for (int k = 0; k < rh.size(); ++k) {
                        if (input[i] == '+')
                            ret.push_back(lh[j] + rh[k]);
                        else if (input[i] == '-')
                            ret.push_back(lh[j] - rh[k]);
                        else if (input[i] == '*')
                            ret.push_back(lh[j] * rh[k]);
                    }
                }
            }
        }
        if (ret.size() > 0)
            return ret;
        int ans = 0;
        for (int i = l; i <= r; ++i)
            ans = ans * 10 + input[i] - '0';
        ret.push_back(ans);
        return ret;
    }

public:
    vector<int> diffWaysToCompute(string input) {
        this->input = input;
        n = input.size();
        return compute(0, n - 1);
    }
};