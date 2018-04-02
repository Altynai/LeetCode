long long MULTIPLY = 0xffffffffffffffff;
char OPERATIONS[3] = {'+', '-', '*'};

class Solution {
private:
    long long* stack;
    char* buf;
    int target;
    string num;
    vector<string> ans;

    void init(const string& num, int target) {
        this->target = target;
        this->num = num;
        int n = num.size();
        stack = new long long[n * 2 + 1];
        buf = new char[n * 2 + 1];
        ans.clear();
    }
    
    bool valid(int nbuf) {
        int i = 0;
        while (i < nbuf) {
            if (i == 0) {
                if (i + 1 < nbuf && buf[i] == '0' && isdigit(buf[i + 1]))
                    return false;
            } else if (!isdigit(buf[i])) {
                if (i + 2 < nbuf && buf[i + 1] == '0' && isdigit(buf[i + 2]))
                    return false;
            }
            i++;
        }
        return true;
    }
    
    void pushStack(long long number, int& nstk) {
        if (nstk >= 2 && stack[nstk - 1] == MULTIPLY) {
            stack[nstk - 2] *= number;
            nstk--;
        }
        else
            stack[nstk++] = number;
    }

    bool equals(int nbuf) {
        int nstk = 0;
        long long number = 0;
        int multiplier = 1;
        for (int i = 0; i < nbuf; i++) {
            if (isdigit(buf[i]))
                number = number * 10 + multiplier * (buf[i] - '0');
            else if (buf[i] == '-') {
                pushStack(number, nstk);
                multiplier = -1;
                number = 0;
            } else if (buf[i] == '+') {
                pushStack(number, nstk);
                multiplier = 1;
                number = 0;
            } else {  // *
                pushStack(number, nstk);
                stack[nstk++] = MULTIPLY;
                multiplier = 1;
                number = 0;
            }
        }
        pushStack(number, nstk);
        long long sum = 0;
        for (int i = 0; i < nstk; i++)
            sum += stack[i];
        return sum == target;
    }

    void dfs(int idx, int nbuf) {
        if (idx == num.size()) {
            if (valid(nbuf) && equals(nbuf))
                ans.push_back(string(buf, buf + nbuf));
            return;
        }
        // do nothing
        buf[nbuf] = num[idx];
        dfs(idx + 1, nbuf + 1);
        // pick an operation
        if (idx > 0 && isdigit(buf[nbuf - 1])) {
            for (int i = 0; i < 3; i++) {
                buf[nbuf] = OPERATIONS[i];
                buf[nbuf + 1] = num[idx];
                dfs(idx + 1, nbuf + 2);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        init(num, target);
        dfs(0, 0);
        return ans;
    }
};