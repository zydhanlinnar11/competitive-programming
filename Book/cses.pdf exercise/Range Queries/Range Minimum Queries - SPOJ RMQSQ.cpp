#include <bits/stdc++.h>
using namespace std;
#define MAXCONST 100000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[MAXCONST], dp[MAXCONST][17], _log[MAXCONST + 1];
    int n, q;
    _log[1] = 0;
    for(int i=2; i<=MAXCONST; i++)
        _log[i] = _log[i >> 1] + 1;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        dp[i][0] = arr[i];
    }
    for(int j=1; j <= _log[n]; j++)
        for(int i=0; i + (1 << j) <= n; i++)
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    cin>>q;
    while(q--) {
        int a, b;
        cin>>a>>b;
        int pangkat = _log[b - a + 1];
        cout<<min(dp[a][pangkat], dp[b - (1 << pangkat) + 1][pangkat])<<'\n';
    }
    return 0;
}