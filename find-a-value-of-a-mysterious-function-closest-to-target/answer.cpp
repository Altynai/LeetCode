class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        set<int> seen;
        int ans = abs(arr[0] - target);

        for(int a : arr) {
            set<int> seen2;
            for(int b : seen) seen2.insert(a & b);
            seen2.insert(a);
            seen = seen2;

            auto it = seen.lower_bound(target);
            if (it != seen.end())
                ans = min(ans, abs(*it - target));
            if (it != seen.begin()) {
                --it;
                ans = min(ans, abs(*it - target));
            }
            
            if (ans == 0) return 0;
        }
        return ans;
    }
};
