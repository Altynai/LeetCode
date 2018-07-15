#define PDI pair<double, int>

struct Compare {
    bool operator()(const PDI& lh, const PDI& rh) {
        return lh.second < rh.second;
    }
};

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size();
        vector<PDI> workers(n);
        for (int i = 0; i < n; i++)
            workers[i] = make_pair(wage[i] / (double)quality[i], quality[i]);
        sort(workers.begin(), workers.end());
        
        int sumq = 0;
        double ans = 0;
        priority_queue<PDI, vector<PDI>, Compare> pq;
        for (int i = 0; i < K; i++) {
            pq.push(workers[i]);
            sumq += workers[i].second;
            ans = sumq * workers[i].first;
        }
        for (int i = K; i < n; i++) {
            PDI worker = pq.top();
            pq.pop();
            sumq -= worker.second;
            sumq += workers[i].second;
            pq.push(workers[i]);
            ans = min(ans, sumq * workers[i].first);
        }
        return ans;
    }
};
