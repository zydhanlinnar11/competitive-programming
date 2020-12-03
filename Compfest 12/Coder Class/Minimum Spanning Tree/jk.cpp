#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    ll jalan[n - 1], res = 0;
    for(int i=0; i<n - 1; i++)
        jalan[i] = INT64_MAX;
    for(int i=0; i<m; i++) {
        int src, dst;
        ll pjk;
        cin>>src>>dst>>pjk;
        src--, dst--;
        src = min(src, dst);
        jalan[src] = min(jalan[src], pjk);
    }
    for(int i=0; i<n - 1; i++)
        res += jalan[i];
    cout<<res<<'\n';
    return 0;
}