// very god use of queues in this problem.

string FirstNonRepeating(string A){
		    unordered_map<char, int> mp;
		    queue<char> q; string ans = "";
		    int n = A.size();
		    for(int i=0; i<n; i++){
		        mp[A[i]]++;
		        q.push(A[i]);
		        while(!q.empty() and mp[q.front()] > 1){
		            q.pop();
		        }
		        if(!q.empty()){
		            ans += q.front();
		        }
		        else{
		            ans += '#';
		        }
		    }
		    
		    return ans;
		}
