
class LRUCache {
private:
    static const int NOT_FOUND = -1;

    struct Node {
        int key;
        int value;
        Node *pre;
        Node *next;
        Node(int _key = 0, int _value = 0): key(_key), value(_value), pre(NULL), next(NULL) {}
    };
    std::map<int, Node * > hash;
    Node *head, *tail;
    int size;
    int n;

    void init(int capacity) {
        head = tail = NULL;
        size = capacity;
        n = 0;
        hash = std::map<int, Node * >();
    }

    void moveNode2Head(Node *current) {
        if (current == head)
            return;
        if (current == tail)
            tail = tail->pre;
        Node *next_node = current->next;
        current->pre->next = next_node;
        if (next_node)
            next_node->pre = current->pre;
        head->pre = current;
        current->next = head;
        current->pre = NULL;
        head = current;
        hash[current->key] = current;
    }

    void popTail() {
        if (n == 0)
            return;
        int key = tail->key;
        if (n == 1)
            head = tail = NULL;
        else {
            tail = tail->pre;
            tail->next = NULL;
        }
        n--;
        hash.erase(key);
    }

    void insert2Head(int key, int value) {
        Node *new_head = new Node(key, value);
        if (n == 0)
            head = tail = new_head;
        else {
            head->pre =  new_head;
            new_head->next = head;
            head = new_head;
        }
        hash[key] = new_head;
        n++;
    }

public:
    LRUCache(int capacity) {
        init(capacity);
    }

    int get(int key) {
        if (hash.find(key) == hash.end())
            return NOT_FOUND;
        Node *ptr = hash[key];
        int result = ptr->value;
        moveNode2Head(ptr);
        return result;
    }

    void set(int key, int value) {
        if (hash.find(key) != hash.end()) {
            Node *ptr = hash[key];
            ptr->value = value;
            moveNode2Head(ptr);
        } else {
            if (n == size)
                popTail();
            insert2Head(key, value);
        }
    }
};
