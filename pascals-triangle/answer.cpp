
class Solution {
private:
    void generateVector(vector<vector<int> > &result, int i, int numRows) {
        if (i == numRows)
            return;
        vector<int> last_row = result[i - 1];
        vector<int> this_row;
        this_row.push_back(1);
        for (int i = 1; i < last_row.size(); i++)
            this_row.push_back(last_row[i] + last_row[i - 1]);
        this_row.push_back(1);
        result.push_back(this_row);
        generateVector(result, i + 1 , numRows);
    }
public:
    vector<vector<int> > generate(int numRows) {
    	if(numRows == 0)
    		return vector<vector<int> >();
        vector<vector<int> > result;
        vector<int> one;
        one.push_back(1);
        result.push_back(one);
        generateVector(result, 1, numRows);
        return result;
    }
};