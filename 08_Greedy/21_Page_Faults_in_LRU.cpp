// Solved by me:
// Here I am using unordered map to keep track of all the elements which are within the cache and we are continuously increating the counter corresponding
// to each element. At every instant we are counting the size of the map. If the map size exceeds the C value then we have to delete the element
// with max counter. Also when the elememts are already there in the map and repeating then have to resent the counter of such element.

// Original solution done in O(1) time:

class LRUCache {
  public:
    class node {
      public:
        int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };

  node * head = new node(-1, -1);
  node * tail = new node(-1, -1);

  int cap;
  unordered_map < int, node * > m;

  LRUCache(int capacity) {
    cap = capacity;
    head -> next = tail;
    tail -> prev = head;
  }

  void addnode(node * newnode) {
    node * temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
  }

  void deletenode(node * delnode) {
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }

  int get(int key_) {
    if (m.find(key_) != m.end()) {
      node * resnode = m[key_];
      int res = resnode -> val;
      m.erase(key_);
      deletenode(resnode);
      addnode(resnode);
      m[key_] = head -> next;
      return res;
    }

    return -1;
  }

  void put(int key_, int value) {
    if (m.find(key_) != m.end()) {
      node * existingnode = m[key_];
      m.erase(key_);
      deletenode(existingnode);
    }
    if (m.size() == cap) {
      m.erase(tail -> prev -> key);
      deletenode(tail -> prev);
    }

    addnode(new node(key_, value));
    m[key_] = head -> next;
  }
};


// Not an efficient solution:

class Solution{
public:
    int pageFaults(int N, int C, int a[]){
        int ans = 0;
        unordered_map<int, int> mp;
        
        for(int i=0; i<N; i++){
            if(mp.find(a[i]) == mp.end()){
                ans++;
            }
            int mc = 0; int mv = INT_MIN;
            for(auto& e : mp){
                if(e.second > mc){
                    mc = e.second;
                    mv = e.first;
                }
                e.second++;
            }
            mp[a[i]] = 1;
            
            if(mp.size() > C){
                mp.erase(mv);
            }
        }
        
        return ans;
    }
};
