class RangeFreqQuery {
private:
#define N 10001

  vector<int> pos[N];

public:
  RangeFreqQuery(vector<int> &a) {
    for (int i = 0; i < N; i++)
      pos[i].clear();
    for (int i = 0; i < a.size(); i++)
      pos[a[i]].push_back(i);
  }

  int query(int l, int r, int val) {
    vector<int> &p = pos[val];
    return upper_bound(p.begin(), p.end(), r) -
           lower_bound(p.begin(), p.end(), l);
  }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
