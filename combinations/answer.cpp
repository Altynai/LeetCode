
class Solution {
private:
    void dfs(vector<vector<int> > &result, int array[], int enumeration, int n, int index, int k) {
        if (index == k) {
            result.push_back(vector<int>(array, array + k));
            return;
        }
    	if(enumeration == n + 1)
    		return;
        // no need to search deeper
        if (n - enumeration + 1 < k - index)
            return;
        // not pick enumeration
        dfs(result, array, enumeration + 1, n, index, k);
        // pick enumeration
        array[index++] = enumeration;
        dfs(result, array, enumeration + 1, n , index, k);
    }

public:
    vector<vector<int> > combine(int n, int k) {
    	int* array = new int[k];
        vector<vector<int> > result;
        dfs(result, array, 1, n, 0, k);
        return result;
    }
};
