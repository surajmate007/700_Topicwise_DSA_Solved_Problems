// Easy implementation by implementinf the trie stri\ucture and then finding the prefix using the custom dependend variable for every node.

class Node{
    public:
    
        Node* links[26];
        bool flag = false;
        int dependend = 0;
        
        bool containsKey(char ch){
            if(links[ch - 'a'] != NULL){
                return true;
            }
            return false;
        }
        
        void putKey(char ch, Node* newNode){
            links[ch - 'a'] = newNode;
        }
        
        Node* getNext(char ch){
            return links[ch - 'a'];
        }
        
        void setLast(){
            flag = true;
        }
};


class Trie{
    private:
    Node* root = new Node();
    
    public:
    
    void insert(string word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                Node* newNode = new Node();
                node->putKey(word[i], newNode);
            }
            
            node->dependend++;
            node = node->getNext(word[i]);
        }
        
        node->setLast();
    }
    
    void getAns(string word, vector<string>& ans){
        Node* node = root;

        for(int i=0; i<word.length(); i++){
            if(node->dependend == 1){
                ans.push_back(word.substr(0, i));
                return;
            }
            node = node->getNext(word[i]);
        }
        ans.push_back(word);
        return;
    }
};


class Solution{
    public:
    vector<string> findPrefixes(string arr[], int n){
        Trie* t = new Trie;
        
        for(int i=0; i<n; i++){
            t->insert(arr[i]);
        }
        
        vector<string> ans;
        
        for(int i=0; i<n; i++){
            t->getAns(arr[i], ans);
        }
        
        return ans;
    }
    
};
