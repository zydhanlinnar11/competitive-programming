#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int main() {
    ll n, m, minn = INT64_MAX, minm = INT64_MAX, maxn = INT64_MIN, maxm = INT64_MIN, resa, resb, l, r;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(ll i=0; i<n; i++) {
        cin>>l>>r;
        if(r < minn)
            minn = r;
        if(l > maxn)
            maxn = l;
    }
    cin>>m;
    for(ll i=0; i<m; i++) {
        cin>>l>>r;
        if(l > maxm)
            maxm = l;
        if(r < minm)
            minm = r;
    }
    resa = maxm - minn;
    resb = maxn - minm;
    if(resa < 0)
        resa = 0;
    if(resb < 0)
        resb = 0;
    cout<<((resa > resb) ? resa : resb)<<endl;
}