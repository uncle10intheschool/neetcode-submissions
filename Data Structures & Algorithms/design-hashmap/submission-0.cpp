class MyHashMap {
private:

    struct Node{
        int key;
        int value;
        Node* pNext;
        Node(int k, int v){
            key = k; value = v; 
            pNext = nullptr;
        }
    };

    int TABLE_SIZE;
    vector<Node*> table;

    int hashFunc(int key){
        return (key%TABLE_SIZE + TABLE_SIZE)%TABLE_SIZE;
    }
public:
    MyHashMap() {
        TABLE_SIZE = 10000;
        table.assign(TABLE_SIZE,nullptr);
    }
    
    void put(int key, int value) {
        int idx = hashFunc(key);
        Node* p = table[idx];
        while (p != nullptr){
            if (p->key == key){
                p->value = value;
                return;
            }
            p = p->pNext;
        }

        Node* newNode = new Node(key,value);
        newNode->pNext = table[idx];
        table[idx] = newNode;
    }
    
    int get(int key) {
        int idx = hashFunc(key);
        Node* p = table[idx];
        while (p != nullptr){
            if (p->key == key){
                return p->value;
            }
            p = p->pNext;
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hashFunc(key);
        Node* curr = table[idx];
        Node* prev = nullptr;
        while (curr != nullptr){
            if (curr->key == key){
                if (prev == nullptr) table[idx] = curr->pNext;
                else prev->pNext = curr->pNext;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->pNext;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */