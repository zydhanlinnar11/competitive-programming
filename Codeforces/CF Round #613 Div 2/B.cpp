#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxSubArraySum(ll a[], ll size) { 
    ll tmax = INT64_MIN, nmax = 0; 
  
    for (ll i = 0; i < size; i++) { 
        nmax = nmax + a[i]; 
        if (tmax < nmax) 
            tmax = nmax; 
  
        if (nmax < 0) 
            nmax = 0; 
    } 
    return tmax; 
}
int main() {
    ll t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) {
        ll sum = 0, * a, n, nmax = 0;
        cin>>n;
        a = new ll[n];
        for(int i=0; i<n; i++) {
            cin>>a[i];
            sum += a[i];
        }
        ll maximum1 = maxSubArraySum((a + 1), (n - 1)), maximum2 = maxSubArraySum(a, (n - 1));
        if(sum > ((maximum1 > maximum2) ? maximum1 : maximum2)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}