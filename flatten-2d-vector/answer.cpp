class Vector2D {
private:
    int row, col;
    int n;
    vector<vector<int>> data;

public:
    Vector2D(vector<vector<int>>& vec2d) {
        data = vec2d;
        row = 0, col = -1;
        n = data.size();
        while (row < n && data[row].size() == 0)
            row++;
    }

    int next() {
        int ans = 0;
        if (col + 1 < data[row].size()) {
            col++;
            ans = data[row][col];
        } else {
            row++;
            while (row < n && data[row].size() == 0)
                row++;
            ans = data[row][0];
            col = 0;
        }
        return ans;
    }

    bool hasNext() {
        if (row >= n)
            return false;
        else if (col + 1 < data[row].size())
            return true;
        else {
            int _row = row + 1;
            while (_row < n && data[_row].size() == 0)
                _row++;
            return _row < n;
        }
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(data);
 * while (i.hasNext()) cout << i.next();
 */