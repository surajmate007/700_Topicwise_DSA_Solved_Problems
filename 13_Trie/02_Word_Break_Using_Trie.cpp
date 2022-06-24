struct Node {
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch){return links[ch-'a']!=NULL;}
    void put(char ch, Node *node){links[ch-'a'] = node;}
    Node *get(char ch){return links[ch-'a'];}
    void setEnd(){flag = true;}
    bool isEnd(){return flag;}
};

class Trie {
    Node *root;
public:
    Trie(){root = new Node();}
    void insert(string word){
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word){
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){return false;}
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    bool startsWith(string word){
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){return false;}
            node = node->get(word[i]);
        }
        return true;
    }
};

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    bool recurse(Trie *trie, string const&A){
        int n = A.length();
        if(n==0){return true;}
        for(int i=1; i<=n; i++){
            if(trie->search(A.substr(0,i)) && recurse(trie, A.substr(i))){return true;}
        }
        return false;
    }
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        int i, j, n=B.size(), m=A.length();
        Trie *trie = new Trie();
        
        for(i=0; i<n; i++){
            trie->insert(B[i]); 
        }
        
        return recurse(trie, A);
    }
};
