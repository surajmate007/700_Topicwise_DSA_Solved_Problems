// most easy approach:

#include<iostream>
using namespace std;
#include<bits/std++.h>


int N, M;
cin>>N>>M;
int arr[N];
for(int i=0; i<N; i++){
	cin>>arr[i];
}
sort(arr, arr+N);
int height = arr[N-1];
while(height >= 0){
	int ans = 0;
	for(int i=N-1; i>=0; i--){
		if(arr[i] <= height){
			break;
		}
		else{
			ans += arr[i]-height;
		}
	}
	if(ans >= M){
		break;
	}
	height++;
}

cout<<height<<endl;





// Approach from reference github profile.
// return amount of wood will be cutted for the given height of machine
ll total_wood(vector<long long>& h, int n, int machine_height) {
    ll wood = 0;
    for (int i = 0;i < n;i++) {
        if (h[i] > machine_height) wood += h[i] - machine_height;
    }
    return wood;
}

void solve() {
    long long n, m;
    cin >> n >> m;

    vector<long long> h(n), res(n);

    ll mx = LONG_LONG_MIN;
    for (int i = 0;i < n;i++) {
        cin >> h[i];
        mx = max(h[i], mx);
    }

    // we will implement binary_search for 0 height to max height
    ll l = 0, r = mx;
    ll ans = 0;
    while (l <= r) {
        // we will find mid and will get wood cutted
        ll mid = l + (r - l) / 2;

        debug(mid);
        ll wood = total_wood(h, n, mid);

        // if wood cutted is of exact amount then ans = mid;
        if (wood == m) {
            ans = mid;
            break;
        }
        // if wood cutted is less then we will decrease the height of the machine.
        else if (wood < m) {
            r = mid - 1;
        }
        // if wood cutted is more than enough then we will store ans as well as increase height of machine.
        else {
            ans = max(ans, mid);
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
