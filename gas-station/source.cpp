#include "vector"
#include "cstdio"
using namespace std;

class Solution {
private:
    static const int NO_SOLUTION = -1;

public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int station_num = gas.size();
        if (station_num == 1)
            return gas[0] >= cost[0] ? 0 : NO_SOLUTION;

        int current = 0, gas_num = 0, start = 0;
        bool is_second_loop = false;

        for (int i = 0; i < station_num;) {
            start = current = i;
            gas_num = 0;
            is_second_loop = false;
            do {
                if (gas_num + gas[current] < cost[current])
                    goto direct_skip;
                else
                    gas_num += gas[current] - cost[current];
                current += 1;
                if (current == station_num)
                    is_second_loop = true;
                current %= station_num;
            } while (start != current);
            if (start == current)
                return current;
direct_skip: {
                if (is_second_loop)
                    break;
                i = current + 1;
            }
        }
        return NO_SOLUTION;
    }
};

int main(int argc, char const *argv[]) {
    Solution *solution = new Solution();
    vector<int> gas;
    gas.push_back(1);
    gas.push_back(2);
    vector<int> cost;
    cost.push_back(2);
    cost.push_back(1);
    printf("%d\n", solution->canCompleteCircuit(gas, cost));
    return 0;
}