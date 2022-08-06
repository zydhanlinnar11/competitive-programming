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

typedef vector<vvl> vvvl;

vvl getSufPrefMax(int n, vl &arr) {
    vvl tmp(2, vl(n));
    tmp[0][0] = arr[0];
    for(int j=1; j<n; j++)
        tmp[0][j] = max(tmp[0][j - 1], arr[j]);
    tmp[1][n-1] = arr[n-1];
    for(int j=n-2; j>=0; j--)
        tmp[1][j] = max(tmp[1][j + 1], arr[j]);
    return tmp;
}

inline void prog() {
    int n;
    cin>>n;
    vl arr(n);
    for(auto &i: arr)
        cin>>i;
    vvvl dp(2, vvl(n));
    pii ans = {-1, -1};
    for(int i=0; i<n; i++) {
        dp[0][i] = dp[1][i] = arr;
        for(int j=0; j<i; j++)
            dp[0][i][j] = min(dp[0][i][j], arr[i]);
        for(int j=n-1; j>i; j--)
            dp[1][i][j] = min(dp[1][i][j], arr[i]);
        auto &[ai, aj] = ans;
        bool can = true;
        auto tmp = getSufPrefMax(n, dp[0][i]);
        for(int j=1; j<n-1; j++)
            can &= !(tmp[0][j - 1] > dp[0][i][j] && tmp[1][j + 1] > dp[0][i][j]);
        if(can && ai == -1)
            ai = 0, aj = i;
        if(can && accumulate(dp[ai][aj].begin(), dp[ai][aj].end(), 0LL) < accumulate(dp[0][i].begin(), dp[0][i].end(), 0LL)) {
            ai = 0, aj = i;
        }
        can = true;
        tmp = getSufPrefMax(n, dp[1][i]);
        for(int j=1; j<n-1; j++)
            can &= !(tmp[0][j - 1] > dp[1][i][j] && tmp[1][j + 1] > dp[1][i][j]);
        if(can && ai == -1)
            ai = 1, aj = i;
        if(can && accumulate(dp[ai][aj].begin(), dp[ai][aj].end(), 0LL) < accumulate(dp[1][i].begin(), dp[1][i].end(), 0LL))
            ai = 1, aj = i;
    }
    vl &tmp = dp[ans.first][ans.second];
    for(int i=0; i<n; i++)
        cout<<tmp[i]<<" \n"[i == n - 1];
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
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}