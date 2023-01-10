#define L 0
#define R 1

template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
  int findCrossingTime(int n, int k, vector<vector<int>> &tm) {
    // efficiency, id
    vector<priority_queue<pair<int, int>>> wait(2);
    // time, id
    vector<min_priority_queue<pair<int, int>>> work(2);
    // last crossing time
    int cur_tm = 0;

    auto getEfficiency = [&](int id) -> int { return tm[id][0] + tm[id][2]; };

    auto finishAndWait = [&](int side) {
      while (work[side].size() and work[side].top().first <= cur_tm) {
        int id = work[side].top().second;
        work[side].pop();
        wait[side].push({getEfficiency(id), id});
      }
    };

    for (int i = 0; i < k; i++)
      wait[L].push({getEfficiency(i), i});

    while (n or (work[R].size() + wait[R].size())) {
      finishAndWait(L);
      finishAndWait(R);

      if (wait[R].size()) {
        int id = wait[R].top().second;
        wait[R].pop();

        cur_tm += tm[id][2];
        work[L].push({cur_tm + tm[id][3], id});
      } else if (wait[L].size() and n) {
        int id = wait[L].top().second;
        wait[L].pop();

        cur_tm += tm[id][0];
        work[R].push({cur_tm + tm[id][1], id});
        n--;
      } else {
        // wait for the first worker to finish
        cur_tm = min((work[L].size() ? work[L].top().first : INT_MAX),
                     (work[R].size() ? work[R].top().first : INT_MAX));
      }
    }
    return cur_tm;
  }
};
