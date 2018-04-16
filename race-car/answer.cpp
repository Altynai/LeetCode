/*

1A: 1
2A: 3
3A: 7
nA: 2^n - 1

dp[target][speed][direction]

A: dp[target - (speed >> 1)][speed >> 1][direction]
R: dp[target][1][direction^1]
*/

#define N 1 << 14
#define M 15

struct Node {
    int current;
    int speed;
    int direction;
    int steps;
    
    Node(int _a, int _b, int _c, int _d) {
        current = _a;
        speed = _b;
        direction = _c;
        steps = _d;
    }
    
    friend bool operator<(const Node& lh, const Node& rh) {
        return lh.steps > rh.steps;
    }
};

class Solution {
private:
    int dp[N][M][2];
    bool update(int& a, int b) {
        if (a == -1 || b < a) {
            a = b;
            return true;
        }
        return false;
    }

public:
    int racecar(int target) {
        int best = -1;
        memset(dp, -1, sizeof(dp));
        dp[0][0][1] = 0;
        priority_queue<Node> que;
        que.push(Node(0, 0, 1, 0));
        while (!que.empty()) {
            Node n = que.top();
            que.pop();
            int current = n.current;
            int direction = n.direction;
            int speed = n.speed;
            int steps = n.steps;
            if (current == target) {
                update(best, steps);
                break;
            }
            // A
            int ncurrent = current + (1 << speed) * (direction == 1 ? 1 : -1);
            int nspeed = speed + 1;
            int nsteps = steps + 1;
            int ndirection = direction;
            if (ncurrent < N && nspeed < M && ncurrent >= 0) {
                if (update(dp[ncurrent][nspeed][ndirection], nsteps)) {
                    que.push(Node(ncurrent, nspeed, ndirection, nsteps));
                }
            }
            // R
            ncurrent = current;
            nspeed = 0;
            nsteps = steps + 1;
            ndirection = direction ^ 1;
            if (update(dp[ncurrent][nspeed][ndirection], nsteps)) {
                que.push(Node(ncurrent, nspeed, ndirection, nsteps));
            }
        }
        return best;
    }
};