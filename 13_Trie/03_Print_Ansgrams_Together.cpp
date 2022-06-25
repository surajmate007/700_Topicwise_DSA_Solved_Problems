// simple implementation using trie.

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
    vector<vector<string> > Anagrams(vector<string>& list) {
        
        // sort(list.begin(), list.end());
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        int n = list.size();
        Trie* trie = new Trie();
        
        
        for(int i=0; i<n; i++){
            string word = list[i];
            sort(word.begin(), word.end());
            if(trie->search(word) == true){
            }
            else{
                trie->insert(word);
            }
            mp[word].push_back(list[i]);
        }
        
        for(auto e : mp){
            ans.push_back(e.second);
        }
        
        return ans;
    }
};
