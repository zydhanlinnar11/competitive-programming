#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mp(x, y) make_pair(x, y)
#define FORINC(i, a, n) for(int i=a; i<n; i++)
#define FORDEC(i, a, n) for(int i=n - 1; i>=a; i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vi> vi2d;
typedef tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007
 
ll modmul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}
 
ll modpow (ll a, ll b) {
    a %= MOD;
    if(b == 1) return a;
    if(b == 0) return 1;
    if(b & 1) {
        return modmul(modpow(a, b - 1), a);
    } else {
        ll res = modpow(a, b >> 1);
        return modmul(res, res);
    }
}
 
ll comb(ll n, ll k, vi &factorial) {
    ll nk = n - k;
    k = modpow(factorial[k], MOD - 2);
    nk = modpow(factorial[nk], MOD - 2);
    return modmul(modmul(factorial[n], k), nk);
}
 
inline void scanArray(vi &arr, int n) {
    FORINC(i, 0, n)
        cin>>arr[i];
}
 
inline void prog() {
    int n, ans = INT_MAX;
    cin>>n;
    vi a(n), sufMin(n + 1);
    scanArray(a, n);
    for(int i=0; i<n; i++) {
        int tmp;
        cin>>tmp;
        sufMin[tmp >> 1] = i;
    }
    for(int i=n-1; i>0; i--) {
        sufMin[i] = min(sufMin[i + 1], sufMin[i]);
    }
    for(int i=0; i<n; i++) {
        ans = min(ans, i + sufMin[(a[i] + 1) >> 1]);
    }
    cout<<ans<<'\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--) prog();
    return 0;
}