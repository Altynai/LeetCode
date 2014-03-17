
class Solution {
private:
    vector<int> makeVector(int index, vector<int> &candidates, vector<int> &count) {
        vector<int> result;
        for (int i = 0; i < index; i++) {
            for (int j = 0; j < count[i]; j++)
                result.push_back(candidates[i]);
        }
        return result;
    }

    void dfs(vector<vector<int> > &result, vector<int> &candidates, int space, int index, vector<int> &count) {
        if (space == 0) {
            result.push_back(makeVector(index, candidates, count));
            return;
        }
        int n = candidates.size();
        if (n == index)
            return;
        int choice = space / candidates[index];
        for (int i = choice; i >= 0; i--) {
            count[index] = i;
            dfs(result, candidates, space - candidates[index] * i, index + 1, count);
        }
    }

public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int n = candidates.size();
        std::sort(candidates.begin(), candidates.end(), std::less<int>());
        vector<int> count(n, 0);
        vector<vector<int> > result;
        dfs(result, candidates, target, 0, count);
        return result;
    }
};