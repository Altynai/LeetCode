#include <cassert>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
private:
    int findInsertIndex(vector<int>& citations, int value) {
        int low = 0, high = citations.size() - 1, mid = 0;
        if (value > citations[high])
            return high + 1;
        int answer = high;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (citations[mid] < value) {
                low = mid + 1;
            }
            else if (citations[mid] > value) {
                high = mid - 1;
                answer = mid;
            }
            else {
                answer = mid;
                high = mid - 1;
            }
        }
        return answer;
    }

public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0)
            return 0;
        sort(citations.begin(), citations.end());
        int low = 0, high = n, mid = 0, answer = 0;
        while (low <= high) {
            mid = (low + high) >> 1;
            int index = findInsertIndex(citations, mid);
            if (n - index >= mid) {
                answer = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return answer;
    }
};

int solve(const string& line) {
    string buf;
    stringstream ss(line);
    vector<int> citations;
    while (ss >> buf)
        citations.push_back(std::stoi(buf));
    Solution* s = new Solution();
    return s->hIndex(citations);
}

int main(int argc, char const *argv[]) {
    assert(1 == solve("1 1 3"));
    assert(0 == solve("0 0"));
    assert(4 == solve("0 1 3 5 5 5 6"));
    assert(3 == solve("3 0 6 1 5"));
    assert(3 == solve("0 3 4 1111"));
    return 0;
}