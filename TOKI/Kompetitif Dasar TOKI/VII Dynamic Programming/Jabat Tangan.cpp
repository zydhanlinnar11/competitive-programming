#include <bits/stdc++.h>
#define MXX 55
using namespace std;
typedef long long ll;
typedef bitset<MXX> bt;
typedef vector<ll> vl;

bt computed;
vl res(MXX);
int n;

inline ll compute(ll n) {
    if(n == 2) return 1;
    if(n < 2) return 0;
    if(computed[n]) return res[n];
    ll ans = 0;
    for(int i=2; i<=n; i++) {
        ll loc_ans = 1;
        loc_ans *= (i != 2 ? compute(i - 2) : 1);
        loc_ans *= (i == n ? 1 : compute(n - i));
        ans += loc_ans;
    }
    computed[n] = true;
    res[n] = ans;
    return ans; 
}

int main() {
    cin>>n;
    cout<<compute(n)<<"\n";
}