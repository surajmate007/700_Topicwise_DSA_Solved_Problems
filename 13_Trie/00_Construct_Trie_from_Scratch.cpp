// Very easy implementation of the trie.

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */


#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MAXN 100001
#define INF 1e18+1

struct Node {
    Node *links[26];
    bool flag = false;
    
    //checks if the reference trie is present or not
    bool containKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    
    //creating reference trie
    void putKey(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
    
    //to get the next node for traversal
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    
    //setting flag to true at the end of the word
    void setEnd() {
        flag = true;
    }
    
    //checking if the word is completed or not
    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;
    
public:
    Trie() {
        //creating new obejct
        root = new Node();
    }

    void insert(string word) {
        //initializing dummy node pointing to root initially
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containKey(word[i])) {
                Node* newNode = new Node();
                node->putKey(word[i], newNode);
            }
            
            //moves to reference trie
            node = node->get(word[i]);
        }
        
        node->setEnd();
    }

    bool search(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->containKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

