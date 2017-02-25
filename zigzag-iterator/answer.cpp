class ZigzagIterator {
public:
    vector<vector<int>> vectors;
    deque<pair<int, int>> q;
    deque<pair<int, int>>::iterator it;

    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        q.clear();
        vectors.clear();
        if (v1.size())
            vectors.push_back(v1);
        if (v2.size())
            vectors.push_back(v2);
        for (int i = 0; i < vectors.size(); ++i)
            q.push_back(make_pair(i, 0));
        it = vectors.size() ? q.begin() : q.end();
    }

    int next() {
        pair<int, int> item = *it;
        int index = item.first, offset = item.second;
        int ans = vectors[index][offset];
        if (offset + 1 < vectors[index].size()) {
            *it = make_pair(index, ++offset);
            it++;
        } else {
            it = q.erase(it);
        }
        if (it == q.end())
            it = q.begin();
        return ans;
    }

    bool hasNext() {
        if (q.empty())
            return false;
        return true;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */