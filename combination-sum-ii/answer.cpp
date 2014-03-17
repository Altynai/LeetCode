

class Solution {
private:
    vector<int> filteCandidates(vector<int> &candidates, int target) {
        vector<int> result;
        for (int i = 0; i < candidates.size(); i++) {
            if (candidates[i] <= target)
                result.push_back(candidates[i]);
        }
        return result;
    }

    vector<int> makeVector(int index, vector<int> &candidates, vector<int> &count) {
        vector<int> result;
        for (int i = 0; i < index; i++) {
            for (int j = 0; j < count[i]; j++)
                result.push_back(candidates[i]);
        }
        return result;
    }

    void dfs(vector<vector<int> > &result, vector<int> &candidates, vector<int> &limits, int space, int index, vector<int> &count) {
        if (space == 0) {
            result.push_back(makeVector(index, candidates, count));
            return;
        }
        int n = candidates.size();
        if (n == index)
            return;
        int choice = std::min(limits[index], space / candidates[index]);
        for (int i = choice; i >= 0; i--) {
            count[index] = i;
            dfs(result, candidates, limits, space - candidates[index] * i, index + 1, count);
        }
    }

public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        candidates = filteCandidates(candidates, target);
        vector<vector<int> > result;
        int n = candidates.size();
        if (n == 0)
            return result;
        std::sort(candidates.begin(), candidates.end(), std::less<int>());
        vector<int> limits(n, 0);
        int m = 1;
        for (int i = 0; i < n; i++) {
            if (candidates[i] == candidates[m - 1])
                limits[m - 1]++;
            else {
                candidates[m] = candidates[i];
                limits[m++] = 1;
            }
        }
        candidates.resize(m);

        vector<int> count(n, 0);
        dfs(result, candidates, limits, target, 0, count);
        return result;
    }
};