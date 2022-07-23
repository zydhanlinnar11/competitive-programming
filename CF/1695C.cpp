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
    vvi arr(n, vi(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>arr[i][j];
        }
    }
    vvi dp1(n, vi(m, INT_MAX)), dp2(n, vi(m, INT_MIN));
    dp1[0][0] = dp2[0][0] = arr[0][0];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i < n - 1) {
                dp1[i + 1][j] = min(dp1[i + 1][j], dp1[i][j] + arr[i + 1][j]);
                dp2[i + 1][j] = max(dp2[i + 1][j], dp2[i][j] + arr[i + 1][j]);
            }
            if(j < m - 1) {
                dp1[i][j + 1] = min(dp1[i][j + 1], dp1[i][j] + arr[i][j + 1]);
                dp2[i][j + 1] = max(dp2[i][j + 1], dp2[i][j] + arr[i][j + 1]);
            }
        }
    }
    if((n + m - 1) % 2 == 0 && dp1[n - 1][m - 1] <= 0 && dp2[n - 1][m - 1] >= 0)
        cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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