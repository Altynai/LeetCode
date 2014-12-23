#include "string"
#include "vector"
#include <stdlib.h>
#include "cstring"
using namespace std;

template <typename Type>
int templateCompare(const Type &x, const Type &y) {
    if (y == x)
        return 0;
    else
        return x > y ? 1 : -1;
}

class Solution {
private:
    vector<int> split(const string &s) {
        int start = 0, end = 0, n = s.size();
        vector<int> result;
        while (start < n) {
            end = start;
            while (end < n && s[end] != '.')
                end++;
            string item = string(s, start, end - start);
            result.push_back(atoi(item.c_str()));
            start = end + 1;
        }
        return result;
    }

    int compareVector(vector<int> &version1, vector<int> &version2) {
        int version1_n = version1.size(), version2_n = version2.size();
        while (version1_n < version2_n) {
            version1.push_back(0);
            version1_n++;
        }
        while (version2_n < version1_n) {
            version2.push_back(0);
            version2_n++;
        }
        for (int i = 0; i < version1_n; i++) {
            int item_compare = templateCompare(version1[i], version2[i]);
            if (item_compare != 0)
                return item_compare;
        }
        return 0;
    }

public:
    int compareVersion(string version1, string version2) {
        vector<int> version1_ints = split(version1);
        vector<int> version2_ints = split(version2);
        return compareVector(version1_ints, version2_ints);
    }
};


int main(int argc, char const *argv[]) {
    Solution *solution = new Solution();
    printf("%d\n", solution->compareVersion("1.0", "1.1"));
    return 0;
}