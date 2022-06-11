// The shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting process with the smallest execution time
// to execute next. SJN, also known as Shortest Job Next (SJN), can be preemptive or non-preemptive.  

// Characteristics of SJF Scheduling:

// Shortest Job first has the advantage of having a minimum average waiting time among all scheduling algorithms.
// It is a Greedy Algorithm.
// It may cause starvation if shorter processes keep coming. This problem can be solved using the concept of ageing.
// It is practically infeasible as Operating System may not know burst times and therefore may not sort them. While it is not possible to predict
// execution time, several methods can be used to estimate the execution time for a job, such as a weighted average of previous execution times. 
// SJF can be used in specialized environments where accurate estimates of running time are available.


// Algorithm: 

// Sort all the processes according to the arrival time. 
// Then select that process that has minimum arrival time and minimum Burst time. 
// After completion of the process make a pool of processes that arrives afterward till the completion of the previous process and select
// that process among the pool which is having minimum Burst time. 



// How to compute below times in SJF using a program? 

// Completion Time: Time at which process completes its execution.
// Turn Around Time: Time Difference between completion time and arrival time. 
// Turn Around Time = Completion Time – Arrival Time
// Waiting Time(W.T): Time Difference between turn around time and burst time. 
// Waiting Time = Turn Around Time – Burst Time



// Advantages of SJF:

// SJF is better than the First come first serve(FCFS) algorithm as it reduces the average waiting time.
// SJF is generally used for long term scheduling
// It is suitable for the jobs running in batches, where run times are already known.
// SJF is probably optimal in terms of average turnaround time.



// Disadvantages of SJF: 

// SJF may cause very long turn-around times or starvation.
// In SJF job completion time must be known earlier, but sometimes it is hard to predict.
// Sometimes, it is complicated to predict the length of the upcoming CPU request.
// It leads to the starvation that does not reduce average turnaround time.



#include <bits/stdc++.h>
using namespace std;


//structure for every process
struct Process {
   int pid; // Process ID
   int bt; // Burst Time
   int art; // Arrival Time
};


void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) {
   for (int i = 0; i < n; i++)
   tat[i] = proc[i].bt + wt[i];
}


//waiting time of all process
void findWaitingTime(Process proc[], int n, int wt[]) {
   int rt[n];
   for (int i = 0; i < n; i++)
   rt[i] = proc[i].bt;
   int complete = 0, t = 0, minm = INT_MAX;
   int shortest = 0, finish_time;
   bool check = false;
   while (complete != n) {
      for (int j = 0; j < n; j++) {
         if ((proc[j].art <= t) && (rt[j] < minm) && rt[j] > 0) {
            minm = rt[j];
            shortest = j;
            check = true;
         }
      }
      if (check == false) {
         t++;
         continue;
      }
      // decrementing the remaining time
      rt[shortest]--;
      minm = rt[shortest];
      if (minm == 0)
         minm = INT_MAX;
         // If a process gets completely
         // executed
         if (rt[shortest] == 0) {
            complete++;
            check = false;
            finish_time = t + 1;
            // Calculate waiting time
            wt[shortest] = finish_time -
            proc[shortest].bt -
            proc[shortest].art;
            if (wt[shortest] < 0)
               wt[shortest] = 0;
         }
         // Increment time
         t++;
   }
}


// Function to calculate average time
void findavgTime(Process proc[], int n) {
   int wt[n], tat[n], total_wt = 0,
   total_tat = 0;
   // Function to find waiting time of all
   // processes
   findWaitingTime(proc, n, wt);
   // Function to find turn around time for
   // all processes
   findTurnAroundTime(proc, n, wt, tat);
   cout << "Processes " << " Burst time " << " Waiting time " << " Turn around time\n";
   for (int i = 0; i < n; i++) {
      total_wt = total_wt + wt[i];
      total_tat = total_tat + tat[i];
      cout << " " << proc[i].pid << "\t\t" << proc[i].bt << "\t\t " << wt[i] << "\t\t " << tat[i] << endl;
   }
   cout << "\nAverage waiting time = " << (float)total_wt / (float)n; cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}


// main function
int main() {
   Process proc[] = { { 1, 5, 1 }, { 2, 3, 1 }, { 3, 6, 2 }, { 4, 5, 3 } };
   int n = sizeof(proc) / sizeof(proc[0]);
   findavgTime(proc, n);
   return 0;
}
 
