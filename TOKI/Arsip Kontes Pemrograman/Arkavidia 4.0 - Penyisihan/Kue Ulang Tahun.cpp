#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main() {
    ull t, a, tmp;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
        a=0;
        ull n, min = UINT64_MAX;
        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>tmp;
            a += tmp;
            min = (tmp < min) ? tmp : min;
        }
        cout<<(a - (n * min))<<'\n';
    }
    return 0;
}