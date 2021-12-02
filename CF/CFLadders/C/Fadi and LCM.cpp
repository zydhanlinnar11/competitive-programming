#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(max(a, b), min(a, b));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    for(ll i=sqrt(n); i >= 1; i--)
        if(n % i == 0 && lcm(i, n / i) == n && (i != (n / i) || i == 1)) {
            cout<<n / i<<' '<<i<<'\n';
            exit(0);
        }
    return 0;
}