// solved using both multiset and priority queue.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
    while(t--){
        long long n, k;
        cin>>n>>k;
        multiset<long long> st;

        for(int i=0; i<n; i++){
            long long a; cin>>a;
            st.insert(a);
        }

        long long ans = 0;

        while(k--){
            auto it = --st.end();
            long long val = *it;
            ans += val;
            st.erase(it);
            st.insert(val/2);
        }

        cout<<ans<<endl;

        // priority_queue<long long> pq;

        // for(long long i=0; i<n; i++){
        //     long long a; cin>>a;
        //     pq.push(a);
        // }

        // long long ans = 0;
        // while(k--){
        //     long long val = pq.top();
        //     ans += val;
        //     pq.pop();
        //     pq.push(val/2);
        // }
    }
}
