class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = 0, n = seats.size();
        for (int j = 0; j < n;) {
            if (seats[j] == 1)
                j++;
            else {
                int i = j;
                // seats[j - 1] = 1
                while (i < n && seats[i] == 0)
                    i++;
                // j - 1 ~ i
                if (j == 0)
                    ans = max(ans, i);
                else if (i == n)
                    ans = max(ans, i - j);
                else {
                    int m = i - j;
                    ans = max(ans, (m + 1) / 2);
                }
                j = i;
            }
        }
        return ans;
    }
};
