class Solution {
private:
    int n;

    bool lessOneByOne(vector<int>& x, int pos) {
        for (int i = pos; i < n; ++i) {
            if (x[i] >= x[i - 2])
                return false;
        }
        return true;
    }
public:
    bool isSelfCrossing(vector<int>& x) {
        n = x.size();
        if (n < 4)
            return false;
        for (int i = 2; i < n; ++i) {
            // edge's length became shorter firstly
            if (x[i] <= x[i - 2]) {
                if (i == 2) {
                    return !lessOneByOne(x, i + 1);
                } else if (i == 3 && x[i] == x[i - 2]) {
                    if (i + 1 < n && x[i + 1] >= x[i - 1] - x[i - 3])
                        return true;
                    else
                        return i + 1 < n ? !lessOneByOne(x, i + 1) : false;
                } else if (i == 3 && x[i] < x[i - 2]) {
                    return !lessOneByOne(x, i + 1);
                } else {
                    if (x[i] >= x[i - 2] - x[i - 4]) {
                        if (i + 1 < n && x[i + 1] >= x[i - 1] - x[i - 3])
                            return true;
                        else
                            return i + 1 < n ? !lessOneByOne(x, i + 1) : false;
                    } else {
                        return !lessOneByOne(x, i + 1);
                    }
                }
            }
        }
        return false;
    }
};