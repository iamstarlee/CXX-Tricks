// 链表还需多加练习
struct DLinkedNode{
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr){}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr){}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        DLinkedNode* node = cache[key];
        move2head(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            add2head(node);
            size++;
            if(size > capacity){
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);

                delete removed;
                size--;
            }
        }
        else{
            DLinkedNode* node = cache[key];
            node->value = value;
            move2head(node);
        }
    }
    void add2head(DLinkedNode* node){
        node->prev = head;
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
    }
    void removedNode(DLinkedNode* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    void move2head(DLinkedNode* node){
        removedNode(node);
        add2head(node);
    }
    DLinkedNode* removeTail(){
        DLinkedNode* node = tail->prev;
        removedNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
