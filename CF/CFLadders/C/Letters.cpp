#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin>>n>>m;
    vector<ll> arr(n + 1, 0);
    arr[0] = 0;
    for(int i=1; i<=n; i++) {
        cin>>arr[i];
        if(i > 1)
            arr[i] += arr[i - 1];
    }
    while(m--) {
        ll place;
        cin>>place;
        ll pos = lower_bound(arr.begin(), arr.end(), place) - arr.begin();
        cout<<pos<<' '<<place - arr[pos - 1]<<'\n';
    }
    return 0;
}