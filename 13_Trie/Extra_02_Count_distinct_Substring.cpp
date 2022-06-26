// Easy approach for every new node added into the trie we will count it as extra substring.
// we will add all possible substrings into the trie.

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

    void insert(string word, int& ans) {
        //initializing dummy node pointing to root initially
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containKey(word[i])) {
                Node* newNode = new Node();
                node->putKey(word[i], newNode);
                ans++;
            }
            
            //moves to reference trie
            node = node->get(word[i]);
        }
        
        node->setEnd();
    }

};

int countDistinctSubstrings(string &s){
    int n = s.length();
    Trie* t = new Trie();
    int ans = 0;
    
    for(int i=0; i<n; i++){
        t->insert(s.substr(i), ans);
    }
    
    return ++ans;
}
