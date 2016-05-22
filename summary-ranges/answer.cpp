class Solution {
private:
    void append(vector<string>& answer, int begins, int ends) {
        if (begins == ends)
            answer.push_back(to_string(begins));
        else
            answer.push_back(to_string(begins) + "->" + to_string(ends));
    }

public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer;
        int n = nums.size();
        if (n == 0)
            return answer;
        int begins = nums[0], ends = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] == ends + 1)
                ends = nums[i];
            else {
                append(answer, begins, ends);
                begins = ends = nums[i];
            }
        }
        append(answer, begins, ends);
        return answer;
    }
};