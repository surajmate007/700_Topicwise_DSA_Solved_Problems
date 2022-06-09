// This is the easiest approach for this problem.
// We are first sorting the jobs according to their profit and then try to do each job on its deadline so that we will get enough margin
// to perform other jobs prior to that.


class Solution {
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job a, Job b){
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) { 
        sort(arr, arr+n, comp);
        
        
        int maxd = 0; 
        for(int i=0; i<n; i++){
            maxd = max(maxd, arr[i].dead);
        }
        
        
        int maxp = 0; int cnt = 0;
        int vec[maxd+1];
        memset(vec, -1, sizeof(vec));
        
        for(int i=0; i<n; i++){
            int dline = arr[i].dead;
            while(vec[dline] != -1 and dline > 0){
                dline--;
            }
            if(dline != 0){
                vec[dline] = arr[i].id;
                maxp += arr[i].profit;
                cnt++;
            }
        }
        
        return {cnt, maxp};
    } 
};
