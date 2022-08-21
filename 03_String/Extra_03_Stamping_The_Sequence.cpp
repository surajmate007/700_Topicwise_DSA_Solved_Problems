// Easy solution using some logic.

class Solution {
public:
    
    int canReplace(string target, string stamp, int pos){
        int n = target.size(); int m = stamp.size();
        for(int i=pos; i<pos+m; i++){
            if(target[i] != '?' and target[i] != stamp[i-pos]){
                return false;
            }
        }
        return true;
    }
    
    
    int replace(string& target, int m, int pos){
        int cnt = 0;
        for(int i=pos; i<pos+m; i++){
            if(target[i] != '?'){
                target[i] = '?';
                cnt++;
            }
        }
        
        return cnt;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size(); int m = stamp.size();
        vector<int> vis(n, 0); vector<int> ans;
        int count = 0;
        
        while(count != n){
            bool flag = false;
            
            for(int i=0; i<=n-m; i++){
                if(vis[i] == 0 and canReplace(target, stamp, i)){
                    vis[i] = 1;
                    count += replace(target, m, i);
                    ans.push_back(i);
                    flag = true;
                    if(count == n){
                        break;
                    }
                }
            }
            
            if(flag == false){
                return {};
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
