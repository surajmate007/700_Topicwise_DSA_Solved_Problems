// simple approach based on greedys algorithm.
// we are first sorting all the jobs based on their profit and then we will try to perform these high profit jobs on their deadline.

/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

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


// Leetcode problem number 1235 is similar to job scheduling where we can use DP because we dont know which job to perform in the given time frame.
// DP + bnary search based approach is used for such problems.


class Solution {
public:
    
    bool static comp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    
    
    int binarySearch(vector<vector<int>> jobs, int index){
	// Initialize 'lo' and 'hi' for Binary Search
        int lo = 0, hi = index - 1;

        // Perform binary Search iteratively
        while (lo <= hi){
            int mid = (lo + hi) / 2;
            if (jobs[mid][1] <= jobs[index][0]){
                if (jobs[mid + 1][1] <= jobs[index][0])
                    lo = mid + 1;
                else
                    return mid;
            }
            else
                hi = mid - 1;
        }
        return -1;
    }
    
    
    int getProfit(vector<vector<int>> jobs, int n){
        int dp[n];
        dp[0] = jobs[0][2];
        
        for (int i=1; i<n; i++){
            // Find profit including the current job
            int inclProf = jobs[i][2];
            int l = binarySearch(jobs, i);
            if (l != -1)
                inclProf += dp[l];

            // Store maximum of including and excluding
            dp[i] = max(inclProf, dp[i-1]);
	    }
        
        int result = dp[n-1];
        return result;
    }
    
    
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
        vector<vector<int>> jobs; int n = startTime.size();
        for(int i=0; i<n; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end(), comp);
        
        return getProfit(jobs, n);
    }
};
