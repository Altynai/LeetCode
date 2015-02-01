#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int common(const string &lh, const string &rh) {
    int n = std::min(lh.size(), rh.size());
    int len = 0;
    for (int i = 0; i < n; i++) {
        if (lh[i] == rh[i])
            len++;
        else
            break;
    }
    return len;
}

int compare(const string &lh, const string &rh) {
    if (lh == rh)
        return 0;

    if (lh.size() == 1 || rh.size() == 1) {
        if (lh.size() == 1) {
            for (int i = 0; i < rh.size(); i++) {
                if (lh[0] != rh[i])
                    return lh[0] < rh[i] ? -1 : 1;
            }
        } else {
            for (int i = 0; i < lh.size(); i++) {
                if (rh[0] != lh[i])
                    return lh[i] < rh[0] ? -1 : 1;
            }
        }
        return 0;
    }

    int common_len = common(lh, rh);
    if (common_len == 0)
        return lh < rh ? -1 : 1;
    else if (common_len == lh.size())
        return compare(lh, rh.substr(common_len));
    else if (common_len == rh.size())
        return compare(lh.substr(common_len), rh);
    else
        return compare(lh.substr(common_len), rh.substr(common_len));
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> s_num;
        for (int i = 0; i < num.size(); ++i)
            s_num.push_back(std::to_string(num[i]));

        for (int i = 0; i < s_num.size(); ++i) {
            for (int j = i + 1; j < s_num.size(); ++j) {
                if (compare(s_num[i], s_num[j]) == 1)
                    std::swap(s_num[i], s_num[j]);
            }
        }

        string result = "";
        for (int i = s_num.size() - 1; i >= 0; i--)
            result += s_num[i];

        int index = 0;
        for (int i = 0; i + 1 < result.size(); i++) {
            if (result[i] == '0' && result[i + 1] == '0')
                index ++;
            else
                break;
        }
        return result.substr(index);
    }
};

void test(int *array, int n) {
    vector<int> num(array, array + n);
    Solution *solution = new Solution();
    cout << solution->largestNumber(num) << "\n";
}

int main(int argc, char const *argv[]) {
    // int array[] = {3, 30, 34, 5, 9};
    // test(array, 5);

    int array2[] = {10, 2};
    test(array2, 2);

    // int array3[] = {3, 34, 30};
    // test(array3, 3);

    // int array4[] = {999999998, 999999997, 999999999};
    // test(array4, 3);
    return 0;
}