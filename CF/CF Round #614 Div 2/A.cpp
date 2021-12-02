#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, s, k;

bool binser(ll n, ll * arr) {
    ll first = 0, last = k;
    while(first <= last) {
        ll mid = first + ((last - first) >> 1);
        if(arr[mid] > n)
            last = mid - 1;
        else if(arr[mid] < n)
            first = mid + 1;
        else
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
        cin>>n>>s>>k;
        ll *a = new ll[k];
        for(ll i=0; i<k; i++) {
            cin>>a[i];
        }
        sort(a, a + k);
        ll level1 = 0, level2 = 0;
        bool uselvl1 = true, uselvl2 = true;
        while((s - level1) >= 1 && binser(s - level1, a))
            level1++;
        if((s - level1) < 1) uselvl1 = false; 
        while((s + level2) <= n && binser(s + level2, a))
            level2++;
        if((s + level2) > n) uselvl2 = false;
        if(!uselvl1) {
            cout<<level2<<'\n';
            continue;
        }
        if(!uselvl2) {
            cout<<level1<<'\n';
            continue;
        }
        cout<<((level1 < level2) ? level1 : level2)<<'\n';
    }
}