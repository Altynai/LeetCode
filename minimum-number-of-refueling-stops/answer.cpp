class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        priority_queue<int> pq;
        int farthest = startFuel, stops = 0;
        for (int i = 0; i < n; i++) {
            int location = stations[i][0], fuel = stations[i][1];
            while (!pq.empty() && farthest < location) {
                farthest += pq.top();
                stops++;
                pq.pop();
            }
            if (farthest < location)
                return -1;
            pq.push(fuel);
        }
        while (!pq.empty() && farthest < target) {
            farthest += pq.top();
            stops++;
            pq.pop();
        }
        return farthest < target ? -1 : stops;
    }
};
