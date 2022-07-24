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

typedef vector<vvi> vvvi;

inline void prog() {
    int n, c;
    cin>>n>>c;
    vii ops(n);
    for(auto &[t, a]: ops)
        cin>>t>>a;
    vvvi dp(n+1, vvi(31, vi(2, 0)));
    for(int i=0; i<31; i++) {
        dp[0][i][0] = 0;
        dp[0][i][1] = 1;
    }
    for(int i=0; i<n; i++) {
        auto &[t, a] = ops[i];
        for(int j=0; j<31; j++) {
            auto parity = (a >> j) & 1;
            if(t == 1) {
                dp[i + 1][j][0] = dp[i][j][0] & parity;
                dp[i + 1][j][1] = dp[i][j][1] & parity;
            } else if(t == 2) {
                dp[i + 1][j][0] = dp[i][j][0] | parity;
                dp[i + 1][j][1] = dp[i][j][1] | parity;
            } else {
                dp[i + 1][j][0] = dp[i][j][0] ^ parity;
                dp[i + 1][j][1] = dp[i][j][1] ^ parity;
            }
        }
    }
    int x = c;
    for(int i=1; i<=n; i++) {
        int tmp = 0;
        for(int j=0; j<31; j++) {
            auto parity = (x >> j) & 1;
            auto res = dp[i][j][parity];
            tmp |= (res << j);
        }
        x = tmp;
        cout<<x<<"\n";
    }
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/Atcoder/abc261/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/Atcoder/abc261/out", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}