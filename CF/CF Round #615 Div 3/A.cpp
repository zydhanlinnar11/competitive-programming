#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll a, b, c, n;
        cin>>a>>b>>c>>n;
        ll sum = a + b + c + n, avg = sum / 3;
        if(((sum % 3) == 0) && (a <= avg) && (b <= avg) && (c <= avg))
            cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}