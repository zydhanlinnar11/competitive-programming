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

typedef tuple<int, ll, ll> pill;
typedef vector<pill> vill;
typedef vector<vill> vvill;

inline void dfs(vvill &adjList, vl &dp, vi &ans, ll sum, int u) {
    if(u != 0) {
        ans[u] = upper_bound(dp.begin(), dp.end(), sum) - dp.begin();
    }
    for(auto &[v, a, b]: adjList[u]) {
        auto val = b;
        if(!dp.empty()) val += dp.back();
        dp.push_back(val);
        dfs(adjList, dp, ans, sum + a, v);
        dp.pop_back();
    }
}

inline void prog() {
    int n;
    cin>>n;
    vvill adjList(n);
    for(int i=1; i<n; i++) {
        int p;
        ll a, b;
        cin>>p>>a>>b;
        p--;
        adjList[p].push_back({i, a, b});
    }
    vl dp;
    vi ans(n, 0);
    dfs(adjList, dp, ans, 0LL, 0);
    for(int i=1; i<n; i++) {
        cout<<ans[i]<<" \n"[i == n - 1];
    }
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