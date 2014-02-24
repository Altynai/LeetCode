
class Solution {
private:
    void dfs(vector<vector<int> > &result, vector<int> &S, int enumeration, int array[], int index) {
        if (enumeration == S.size()) {
            result.push_back(vector<int>(array, array + index));
            return;
        }
        // not pick enumeration
        dfs(result, S, enumeration + 1, array, index);
        // pick enumeration
        array[index++] = S[enumeration];
        dfs(result, S, enumeration + 1, array, index);
    }

public:
    vector<vector<int> > subsets(vector<int> &S) {
        std::sort(S.begin(), S.end());
        int n = std::unique(S.begin(), S.end()) - S.begin();
    	int* array = new int[n];
        vector<vector<int> > result;
        dfs(result, S, 0, array, 0);
        return result;
    }
};