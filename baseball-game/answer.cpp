#define N 1001

class Solution {
private:
    int nums[N], n;

    int convert(const string& number) {
        int ans = 0;
        for (int i = 0; i < number.size(); i++)
            if (number[i] != '-')
                ans = ans * 10 + number[i] - '0';
        return number[0] == '-' ? -ans : ans;
    }

public:
    int calPoints(vector<string>& ops) {
        n = 0;       
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "C")
                n--;
            else if (ops[i] == "D") {
                nums[n] = nums[n - 1] * 2;
                n++;
            }
            else if (ops[i] == "+") {
                nums[n] = nums[n - 1] + nums[n - 2];
                n++;
            }
            else {
                nums[n] = convert(ops[i]);
                n++;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += nums[i];
        return ans;
    }
};