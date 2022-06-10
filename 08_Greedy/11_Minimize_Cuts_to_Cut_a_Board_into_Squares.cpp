// Here the approach is simple we are first sorting the horizontal and verticval cut array in descending order and then we start cutting from max cost.
// Initially we are giving higher cost cuts because the nu,ber of pieces will be less and as the nu,ber of pieces increases we qwill use the 
// lower costcuts to reduce the overall cost.

// Vertical cut will increse number of horizontal pieces and horizontal cut will increase number of vertical pieces.

class Solution {
public:
    int minimumCostOfBreaking(vector<int> v, vector<int> h, int m, int n){
        int cost = 0;
        sort(v.begin(), v.end(), greater<int>());
        sort(h.begin(), h.end(), greater<int>());
        
        int i = 0; int j = 0; int vp = 1; int hp = 1;
    
        while(i<=m-1 and j<=n-1){
            if(v[i] == h[j]){
                cost += (v[i] * vp);
                hp++; i++;
            }
            else if(v[i] > h[j]){
                cost += (v[i] * vp);
                hp++; i++;
            }
            else{
                cost += (h[j] * hp);
                vp++; j++;
            }
        }
        
        while(i <= m-1){
            cost += (v[i] * vp);
            hp++; i++;
        }
        
        while(j <= n-1){
            cost += (h[j] * hp);
            vp++; j++;
        }
        
        return cost;
    }
};
