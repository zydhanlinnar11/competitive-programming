#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull power[64];
    power[0] = 1;
    for(ull i=1; i<64; i++)
        power[i] = power[i - 1] * 2;
    ull t, n;
    cin>>t;
    for(ull i = 0; i<t; i++) {
        cin>>n;
        ull res = 0;
        res += ((n + 1) / 2);
        for(ull j=1; j<64 && power[j] <= n; j++) {
            ull berapaJ = ((n - power[j]) / power[j + 1]) + 1;
            res += (j + 1) * berapaJ;
        }
        cout<<res<<'\n';
    }
    return 0;
}