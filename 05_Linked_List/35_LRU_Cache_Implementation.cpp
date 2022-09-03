// Both put and get operations are performed in O(1) time hence efficient this way.
// we are simply implementing class Node which is storing the key and value for each node.
// the recently used node will be placed just after the haed and the least recently used node will be rpesent near the tail at last.
// when the size exceeds the limits then we are deleting the node from the tail end of the DLL.


class Node{
public:
    int key, val;
    Node* next; Node* prev;
    Node(int _key, int _val){
        key = _key; val = _val;
    }
};

class LRUCache {
public:
    
    unordered_map<int, Node*> mp;
    int cap = 0; Node* head = new Node(-1, -1); Node* tail = new Node(-1, -1);
    
    void addNode(Node* nd){
        Node* temp = head->next;
        head->next = nd;
        nd->prev = head;
        nd->next = temp;
        temp->prev = nd;
        mp[nd->key] = head->next;
    }
    
    void deleteNode(Node* nd){
        mp.erase(nd->key);
        nd->prev->next = nd->next;
        nd->next->prev = nd->prev;
    }
    
    LRUCache(int capacity) {
        cap = capacity;
        mp.clear();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        int res = -1;
        if(mp.find(key) != mp.end()){
            Node* nd = mp[key];
            res = nd->val;
            deleteNode(nd);
            Node* node = new Node(key, res);
            addNode(node);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* nd = mp[key];
            deleteNode(nd);
        }
        if(mp.size() == cap){
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
