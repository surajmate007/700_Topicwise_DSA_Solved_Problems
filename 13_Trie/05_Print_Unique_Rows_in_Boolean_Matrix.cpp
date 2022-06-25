// Very easy and intuitive solution.

struct Node {
    Node *links[2];
    bool flag = false;
    bool containsKey(char ch){return links[ch-'0']!=NULL;}
    void put(char ch, Node *node){links[ch-'0'] = node;}
    Node *get(char ch){return links[ch-'0'];}
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


/*You are required to complete this function*/
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col){
    vector<vector<int>> ans;
    Trie* t = new Trie();
    
    for(int i=0; i<row; i++){
        string str = "";
        for(int j=0; j<col; j++){
            str += (to_string(M[i][j]));
        }
        // cout<<str<<endl;
        if(t->search(str) == false){
            vector<int> vec;
            for(int k=0; k<col; k++){
                vec.push_back(M[i][k]);
            }
            
            ans.push_back(vec);
            t->insert(str);
        }
    }
    
    return ans;
}
