// Simple solution using bfs.
// Revise frequently.

class Solution{
public:
    int ladderLength(string start, string end, vector<string> &dictV){
        unordered_set<string> dict(dictV.begin(), dictV.end());
        unordered_map<string, int> mp;
        queue<string> q;

        mp[start] = 1;
        q.push(start);
        dict.erase(start);

        while (!q.empty()){
            auto word = q.front();
            q.pop();
            if (word == end){
                break;
            }

            for (int i = 0; i < word.size(); i++){
                for (int j = 0; j < 26; j++){
                    auto temp = word;
                    temp[i] = 'a' + j;

                    if (dict.find(temp) != dict.end() && mp.find(temp) == mp.end()){
                        mp[temp] = mp[word] + 1;
                        q.push(temp);
                        dict.erase(temp);
                    }
                }
            }
        }

        if (mp.find(end) == mp.end()){
            return 0;
        }
        return mp[end];
    }
};
