class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int p = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        deque<int> d;
        int i = p - 1, j = p;
        if (arr[p] == x) {
            d.push_back(x);
            i = p - 1;
            j = p + 1;
            k--;
        }
        while (k--) {
            bool front = false;
            if (i >= 0 && j >= n)
                front = true;
            else if (i >= 0 && j < n && abs(arr[i] - x) <= abs(arr[j] - x))
                front = true;

            if (front)
                d.push_front(arr[i--]);
            else
                d.push_back(arr[j++]);
        }
        return vector<int>(d.begin(), d.end());
    }
};
