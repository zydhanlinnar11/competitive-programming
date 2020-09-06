#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin>>n>>m;
    if(m * 5 < n || n < m)
        cout<<"-1 -1\n";
    else {
        ll maks = (n-m) / 4;
        ll min = 0;
        if((m * 5 - n) < m)
            min = m - (m * 5 - n);
        cout<<min<<' '<<maks<<'\n';
    }
    return 0;
}