// This is the brute force approach for this problem wehre we are firts sorting all the meetings according to their finish time and then 
// traversing over the sorted array and finding the maximum meetings possible.

class Solution{
  public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(pair<int, int>& a, pair<int, int>& b){
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n){
        vector<pair<int, int>> meet;
        for(int i=0; i<n; i++){
            meet.push_back({start[i], end[i]});
        }
        
        sort(meet.begin(), meet.end(), comp);
    
        int ans = 1;
        pair<int, int> pr = meet[0];
        for(int i=1; i<n; i++){
            if(pr.second < meet[i].first){
                ans++;
                pr = meet[i];
            }
        }
        
        return ans;
    }
};
