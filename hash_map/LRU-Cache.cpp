class LRUCache {
public:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1); 
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void moveToFront(Node* node) {
        removeNode(node);
        addNode(node);
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;  
        Node* node = cache[key];
        moveToFront(node);  
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
        } else {
            if (cache.size() >= capacity) {
                Node* nodeToRemove = tail->prev;
                cache.erase(nodeToRemove->key);
                removeNode(nodeToRemove);
                delete nodeToRemove;
            }

            Node* newNode = new Node(key, value);
            addNode(newNode);
            cache[key] = newNode;
        }
    }
};
