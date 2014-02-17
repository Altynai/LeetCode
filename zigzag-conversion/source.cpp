#include "vector"
#include "string"
#include "iostream"
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        vector<vector<char> > zigzag;
        for (int i = 0; i < nRows; i++)
            zigzag.push_back(vector<char>());
        int index = 0, stop = nRows, delta = 1;
        for (int i = 0; i < s.size(); i++) {
            zigzag[index].push_back(s[i]);
            index += delta;
            if (index == stop) {
                if (stop == nRows) {
                    index = max(0, nRows - 2);
                    delta = -1;
                    stop = -1;
                } else {
                	stop = nRows;
                    index = min(nRows - 1, 1);
                    delta = 1;
                }
            }
        }
        string result = "";
        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < zigzag[i].size(); j++)
                result.push_back(zigzag[i][j]);
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
    Solution *solution = new Solution();
    cout << solution->convert("AB", 1) << endl;
    return 0;
}