#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fpb(ll a, ll b) {
    if(b % a == 0) return a;
    else return fpb(b % a, a);
}
int main() {
    ll x, now;
    cin>>x;
    if(x == 1) {
        cout<<"1 1\n";
        return 0;
    }
    for(ll i=1; i*i<x; i++) {
        ll p2 = x / i;
        if((i * p2 / fpb(i, p2)) == x) now = i;
    }
    cout<<now<<' '<<(x / now)<<'\n';
}