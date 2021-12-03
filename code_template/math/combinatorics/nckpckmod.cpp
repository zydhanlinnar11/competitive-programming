#include <vector>
typedef long long ll;
using namespace std;
#define MOD ((int)1e9)+7
#define MAX_FACT 200001
vector<ll> fct(MAX_FACT, 1);

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline ll modpow (ll a, ll b, ll mod = MOD) {
    a %= mod;
    if(b == 1) return a;
    if(b == 0) return 1;
    if(b & 1) {
        return modmul(modpow(a, b - 1), a);
    } else {
        ll res = modpow(a, b >> 1);
        return modmul(res, res);
    }
}

inline ll perm(ll n, ll k, vector<ll> &factorial, ll mod = MOD) {
    if(n < k)
        swap(n, k);
    ll nk = n - k;
    if(nk < 0) return 1;
    k = modpow(factorial[k], mod - 2);
    nk = modpow(factorial[nk], mod - 2);
    return modmul(factorial[n], nk);
}

inline ll comb(ll n, ll k, vector<ll> &factorial, ll mod = MOD) {
    return modmul(perm(n, k, factorial, mod), modpow(factorial[k], mod - 2));
}

int main() {
    for(int i=1; i<MAX_FACT; i++)
        fct[i] = modmul(fct[i - 1], i);
}