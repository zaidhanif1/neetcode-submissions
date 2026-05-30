class LRUCache {
public:
    struct Node
    {
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int k, int v)
        {
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };


    int cap;
    int curr_cap;
    std::unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) 
    {
        this->cap = capacity;
        curr_cap = 0;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }
    void insert(Node* node)
    {
        //always insert at the head
        Node* old_head = head->next;

        old_head->prev = node;
        head->next = node;

        node->prev = head;
        node->next = old_head;
    }

    void remove(Node* node)
    {
        Node* before = node->prev;
        Node* after = node->next;

        before->next = after;
        after->prev = before;

        node->prev = nullptr;
        node->next = nullptr;

        return;

    }

    int get(int key) 
    {
        if ( mp.find(key) == mp.end() )
        {
            return -1;
        }
        Node* node = mp[key];

        remove(node); //remove it from list
        insert(node); //reinsert at mru position (left pointer) 
        return node->val;
    }

    void put(int key, int value) 
    {
        //check if val exists, update value pair if it does
        if (mp.find(key) != mp.end())
        {
            Node* node = mp[key];
            node->val = value;

            remove(node);
            insert(node);

            return;
        }
        if (mp.size() == cap)
        {
            Node* lru = tail->prev;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
        Node* new_node = new Node(key, value);
        mp[key] = new_node;
        insert(new_node);

        return;


    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */