class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0)
            return 0;
        int previous = -1, count = 0, answer = 0;
        for (int i = 0; i < n; ++i) {
            if (citations[i] == previous)
                count++;
            else {
                answer = max(answer, min(n - i + count, previous));
                previous = citations[i];
                count = 1;
            }
        }
        answer = max(answer, min(previous, count));
        return answer;
    }
};