using int64 = long long;

template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
  int mostBooked(int n, vector<vector<int>> &meetings) {
    int m = meetings.size();
    sort(meetings.begin(), meetings.end());

    vector<int64> end(n, -1);
    vector<int> cnt(n, 0);

    auto findRoom = [&]() -> int {
      for (int i = 0; i < n; i++) {
        if (end[i] == -1) {
          return i;
        }
      }
      return -1;
    };

    // <when the meeting ends, room>
    min_priority_queue<pair<int64, int>> pq;
    for (auto &ms : meetings) {
      int64 s = ms[0], e = ms[1];
      int64 when = s;

      // freeup rooms
      while (!pq.empty() and s >= pq.top().first) {
        end[pq.top().second] = -1;
        pq.pop();
      }

      // wait unit the first room is available
      int room = findRoom();
      if (room == -1) {
        when = pq.top().first;
        room = pq.top().second;
        pq.pop();
      }
      assert(room != -1);

      cnt[room]++;
      end[room] = when + (e - s);
      pq.push({end[room], room});
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
      if (cnt[i] > cnt[ans])
        ans = i;
    }
    return ans;
  }
};
