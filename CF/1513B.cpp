#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mp(x, y) make_pair(x, y)
using namespace std;
using namespace chrono;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vi2d;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vl2d;
typedef vector<string> vs;
typedef vector<vs> vs2d;
typedef vector<pii> vii;
typedef vector<pll> vll;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

vl fact(2e5+5);

inline ll modPow(ll a, ll b) {
    if(b == 0 || a == 1) return 1;
    if(a == 0) return 0;
    if(b == 1) return a % MOD;
    if(b & 1) {
        return modmul(modPow(a, b - 1), modPow(a, 1));
    }
    auto half = modPow(a, b >> 1);
    return modmul(half, half);
}

inline void prog() {
    int n; cin>>n;
    vi arr(n);
    int nd = INT_MAX;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        nd &= arr[i];
    }
    int cnt = count(arr.begin(), arr.end(), nd);
    if(cnt < 2) {
        cout<<"0\n";
        return;
    }
    cout<<modmul(modmul(fact[cnt], fact[n - 2]), modPow(fact[cnt - 2], MOD - 2))<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0] = 1;
    for(int i=1; i<(int)fact.size(); i++)
        fact[i] = modmul(fact[i - 1], i);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/CF/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/CF/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}