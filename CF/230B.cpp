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
}using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (u64 a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

inline void prog() {
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        ll tmp;
        cin>>tmp;
        ll sqr = sqrt(tmp);
        cout<<(sqr*sqr == tmp && MillerRabin(sqr) ? "YES\n" : "NO\n");
    }
}

int main() {
    // for(int i=1; i<MAX_FACT; i++)
    //     fct[i] = modmul(fct[i - 1], i);
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