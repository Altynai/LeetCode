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