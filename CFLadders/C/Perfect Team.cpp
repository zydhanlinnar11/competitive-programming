#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    while(n--) {
        int c, m, x;
        cin>>c>>m>>x;
        cout<<min(min(c, m), (c + m + x) / 3)<<'\n';
    }
    return 0;
}