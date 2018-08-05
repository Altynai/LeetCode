class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boats = 0;
        for (int i = 0, j = people.size() - 1; i <= j; j--) {
            if (i < j && people[i] + people[j] <= limit)
                i++;
            boats++;
        }
        return boats;
    }
};
