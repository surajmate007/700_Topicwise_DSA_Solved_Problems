// simple approiach using proiority queue where the top element in the min queue gives the minimum limit of the answer and the top element in the maxq 
// gives the upper limit of the answer. Everytime we are poping out the top element of the minheap and then pushing the next element in the same roq of the
// matrix. This solution is not running properly.


typedef pair<int, int> pi;

class Solution{
    public:
    
    pair<int,int> findSmallestRange(int a[][N], int n, int k){
          priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> mn;
          priority_queue<int> mx;
          pi ans; int dif = INT_MAX;
          
          for(int i=0; i<k; i++){
              mn.push({a[i][0], {i, 0}});
              mx.push(a[i][0]);
          }
          dif = min(dif, mx.top() - mn.top().first);
          ans = {mn.top().first, mx.top()};
          int midx = 1;
          
          while(midx < n){
              int row = mn.top().second.first; int col = mn.top().second.second;
              int val = a[row][col+1];
              
              mn.pop();
              mn.push({val, {row, col+1}});
              mx.push(val);
              int ndif = mx.top() - mn.top().first;
              
              if(dif > ndif){
                  dif = ndif;
                  ans = {mn.top().first, mx.top()};
              }
         
              midx = max(midx, col+1);
          }
          
          return ans;
    }
};



// This solution is based on the same approach and giving correct ressult. 
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k){
          //code here
          int i,minelem=INT_MAX,maxelem=INT_MIN,ans=INT_MAX,mini,maxi;
          priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
          
          for(i=0;i<k;i++){
              pq.push({arr[i][0],{i,0}});
              maxelem=max(maxelem,arr[i][0]);
          }
          
          while(1){
              pair<int,pair<int,int>> p=pq.top();
              pq.pop();
              minelem=p.first;
              
              if((maxelem-minelem)<ans){
                  ans=maxelem-minelem;
                  mini=minelem;
                  maxi=maxelem;
              }
              
              if(p.second.second+1<n){
                  maxelem=max(maxelem,arr[p.second.first][p.second.second+1]);
                  pq.push({arr[p.second.first][p.second.second+1],{p.second.first,p.second.second+1}});
              }
              
              else
              break;
          }
          
          return {mini,maxi};
    }
};
