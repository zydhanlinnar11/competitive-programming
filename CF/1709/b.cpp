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
typedef vector<vi> vvi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void prog() {
    int n, m;
    cin>>n>>m;
    vl arr(n);
    for(auto &i: arr)
        cin>>i;
    vvl dp(2, vl(n, 0));
    for(int i=0; i<n; i++) {
        if(i > 0 && arr[i] < arr[i - 1])
        dp[0][i] = arr[i - 1] - arr[i];
    }
    for(int i=n-1; i>=0; i--) {
        if(i < n - 1 && arr[i] < arr[i + 1])
        dp[1][i] = arr[i + 1] - arr[i];
    }
    for(int i=1; i<n; i++)
        dp[0][i] += dp[0][i - 1];
    for(int i=n-2; i>=0; i--)
        dp[1][i] += dp[1][i + 1];
    while(m--) {
        int s, t;
        cin>>s>>t;
        ll ans = 0;
        if(s < t) {
            ans += dp[0][t-1];
            if(s >= 1) ans -= dp[0][s-1];
        } else {
            ans += dp[1][t-1];
            if(s < n) ans -= dp[1][s-1];
        }
        cout<<ans<<"\n";
    }
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/CF/1709/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/CF/1709/out", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}