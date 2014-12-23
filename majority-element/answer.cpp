class Solution {
public:
    int majorityElement(vector<int> &num) {
        map<int, int> hash;
        int n = num.size();
        for (int i = 0; i < n; i++)
            hash[num[i]]++;
        for (map<int, int>::iterator i = hash.begin(); i != hash.end(); i++) {
            if (i->second > n / 2)
                return i->first;
        }
    }
};