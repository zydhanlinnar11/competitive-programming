#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull gcd(ull a, ull b) {
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin>>q;
    while(q--) {
        ull n, x, y;
        cin>>n>>x>>y;
        ull kpk = x*y/gcd(max(x, y), min(x, y));
        cout<<(n/x) - (n/kpk)<<' '<<(n/y) - (n/kpk)<<'\n';
    }
}