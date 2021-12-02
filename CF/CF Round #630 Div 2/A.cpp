#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, a, b, c, d, x, y, x1, y1, x2, y2;
    cin>>t;
    while(t--) {
        cin>>a>>b>>c>>d;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        if(!(((x - a + b) <= x2 && (x - a + b) >= x1) && ((y - c + d) <= y2 && (y - c + d) >= y1))
        || ((x1 == x && x == x2) && (b > 0 || a > 0)) || ((y1 == y && y == y2) && (c > 0 || d > 0))) cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}