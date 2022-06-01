/*
    using map
    TC: O(n)
    SC: O(n)
*/
int majorityElement(int a[], int size)
{

    // your code here
    map<int, int> mp;
    for (int i = 0;i < size;i++) {
        mp[a[i]]++;
    }
    for (auto i : mp) {
        if (i.second > size / 2) {
            return i.first;
        }
    }
    return -1;

}


// Using Moores Voting algorithm:
// tHE SIMPLE APPROACH THAT WE LEARNED IN ARRAY SECTION TO FIND THE MAJOTRITY ELEMENT IS USING ELE1 AND ELE2 AND CNT1 AND CNT2:
// The majority element is that number whiose frequency in the array is more than (size of array)/2 times.

int majorityElement(int a[], int size){
        int cnt1 = 0; int cnt2 = 0;
        int ele1 =-1, ele2=-1;
        for(int i=0; i<size; i++){
            int ele = a[i];
            if(ele == ele1){
                cnt1++;
            }
            else if(ele == ele2){
                cnt2++;
            }
            else if(cnt1==0){
                ele1 = ele;
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                ele2 = ele;
                cnt2++;
            }
            else{
                cnt1--; cnt2--;
            }
        }
        
        cnt1 = 0; cnt2 = 0;
        for(int i=0; i<size; i++){
            int ele = a[i];
            if(ele == ele1){
                cnt1++;
            }
            else if(ele == ele2){
                cnt2++;
            }
        }
        
        if(cnt1 != cnt2 and cnt1 > size/2){
            return ele1;
        }
        if(cnt1 != cnt2 and cnt2 > size/2){
            return ele2;
        }
        return -1;
    }





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Using Moore’s Voting Algorithm
    TC: O(n)
    SC: O(1)
*/
// C++ Program for finding out
// majority element in an array
#include <bits/stdc++.h>
using namespace std;

/* Function to find the candidate for Majority */
int findCandidate(int a[], int size)
{
    int maj_index = 0, count = 1;
    for (int i = 1; i < size; i++) {
        if (a[maj_index] == a[i])
            count++;
        else
            count--;
        if (count == 0) {
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index];
}
