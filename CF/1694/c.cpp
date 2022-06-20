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
typedef vector<ll> vll;
typedef vector<vll> vll2d;
typedef vector<string> vs;
typedef vector<vs> vs2d;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void prog() {
    int n; cin>>n;
    vll a(n); for(ll &i: a) cin>>i;
    auto sum = accumulate(a.begin(), a.end(), 0LL);
    bool can = (sum == 0);
    vll b(n); b[0] = a[0]; 
    for(int i=1; i<n; i++) {
        ll ci = b[i - 1];
        b[i] = a[i] + ci;
        if((b[i] != 0 || ci != 0) && ci <= 0) can = false;
    }
    #ifdef ZYD_WSL
        for(auto &i: b) cerr<<i<<" ";
        cerr<<"\n";
    #endif
    vs ans = {"No", "Yes"};
    cout<<ans[can]<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/CF/1694/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/CF/1694/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}