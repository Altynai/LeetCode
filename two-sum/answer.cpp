
class HashTable {
private:
    struct Entry {
        int index;
        int value;
        Entry *next;
        Entry(int _index, int _value) {
            index = _index;
            value = _value;
            next = NULL;
        }
    };

    static const int INDEX_NOT_FOUND = -1;
    static const int MASK = 0xfff;
    static const int BUCKET_COUNT = 0xfff + 1;
    Entry *buckets[BUCKET_COUNT];

    bool hasValue(int bucket_id, int not_index, int value) {
        Entry *head = buckets[bucket_id];
        while (head != NULL) {
            if (head->value == value && head->index != not_index)
                return true;
            head = head->next;
        }
        return false;
    }

    int getIndex(int bucket_id, int value) {
        Entry *head = buckets[bucket_id];
        while (head != NULL) {
            if (head->value == value)
                return head->index;
            head = head->next;
        }
        return INDEX_NOT_FOUND;
    }

    void insert(int bucket_id, int index, int value) {
        Entry *head = buckets[bucket_id];
        Entry *new_head = new Entry(index, value);
        if (head != NULL)
            new_head->next = head->next;
        buckets[bucket_id] = new_head;
    }

public:
    HashTable() {
        for (int i = 0; i < BUCKET_COUNT; ++i)
            buckets[i] = NULL;
    }

    bool hasValue(int not_index, int value) {
    	// has value but not with `index` = not_index
        int bucket_id = MASK & value;
        return hasValue(bucket_id, not_index, value);
    }

    int getIndex(int value) {
        int bucket_id = MASK & value;
        return getIndex(bucket_id, value);
    }

    void insert(int index, int value) {
        int bucket_id = MASK & value;
        insert(bucket_id, index, value);
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        HashTable *ht = new HashTable();
        for (int i = 0; i < numbers.size(); i++)
            ht->insert(i + 1, numbers[i]);

        int result[2] = {0, 0};
        for (int i = 0; i < numbers.size(); i++) {
            if (ht->hasValue(i + 1, target - numbers[i])) {
                result[0] = i + 1;
                result[1] = ht->getIndex(target - numbers[i]);
                break; // make sure: index1 must be less than index2
            }
        }
        return vector<int>(result, result + 2);
    }
};