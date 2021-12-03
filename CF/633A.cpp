#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mp(x, y) make_pair(x, y)
#define FORINC(i, a, n) for(int i=a; i<n; i++)
#define FORDEC(i, a, n) for(int i=n - 1; i>=a; i--)
using namespace std;
using namespace chrono;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vi> vi2d;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MAX_FACT 200001
#define MOD 1000000007
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

inline void scanArray(vi &arr, int n) {
    FORINC(i, 0, n)
        cin>>arr[i];
}

inline ll gcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll ans = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return ans;
}

inline void prog() {
    ll a, b, c, x, y;
    cin >> a >> b >> c;
    ll g = gcd(a, b, x, y);
    bool noans = c % g != 0;
    if(noans) {
        cout << "No\n";
        return;
    }
    x *= c / g;
    y *= c / g;
    if(x < 0) {
        while(x < 0) {
            x += b / g;
            y -= a / g;
        }
    } else if(y < 0) {
        while(y < 0) {
            x -= b / g;
            y += a / g;
        }
    }
    cout << ((x >= 0 && y >= 0) ? "Yes\n" : "No\n");
}

int main() {
    for(int i=1; i<MAX_FACT; i++)
        fct[i] = modmul(fct[i - 1], i);
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}