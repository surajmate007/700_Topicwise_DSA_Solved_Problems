// simple solution using trie:
// TC = O(32 * n)


class Node{
    Node* links[2];

    public:
    bool contains_key(int bit){
        return (links[bit]!=NULL);
    }

    void put(int bit,Node *temp){
        links[bit]=temp;
    }

    Node *get(int bit){
        return links[bit];
    }
};

class Trie{
    Node *root;
    public:
    Trie(){
        root=new Node();
    }

    void insert(int num){
        Node *node=root;
        for(int i=31;i>=0;i--){
            int bit=((num>>i)&1);
            if(!node->contains_key(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }

    int max_xor(int num){
        int mx=0;
        Node *node=root;
        for(int i=31;i>=0;i--){
            int bit=((num>>i)&1);
            if(node->contains_key(!bit)){
                mx=((1<<i)|mx);
                node=node->get(!bit);
            }
            else
                node=node->get(bit);
        }
        return mx;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mx=0;
        Trie trie;
        for(auto i:nums)
            trie.insert(i);
        for(auto i:nums)
            mx=max(mx,trie.max_xor(i));
        return mx;
    }
};
