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
    int n, m;
    cin>>n>>m;
    // 0 train, 1 bus
    vvvi adjLists(2, vvi(n));
    for(int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        adjLists[0][u].push_back(v);
        adjLists[0][v].push_back(u);
        adjLists[1][u].push_back(v);
        adjLists[1][v].push_back(u);
    }
    for(int i=0; i<n; i++)
        sort(adjLists[1][i].begin(), adjLists[1][i].end());
    queue<pii> q;
    vi dist(n, INT_MAX);
    dist[0] = 0;
    q.push({0, 0});
    while(!q.empty()) {
        auto [d, u] = q.front();
        q.pop();
        for(auto &v: adjLists[0][u]) {
            if(d + 1 >= dist[v])
                continue;
            dist[v] = d + 1;
            q.push({d + 1, v});
        }
    }
    int ans = dist[n - 1];
    dist = vi(n, INT_MAX);
    dist[0] = 0;
    q.push({0, 0});
    while(!q.empty()) {
        auto [d, u] = q.front();
        q.pop();
        for(int v=0; v<n; v++) {
            auto lb = lower_bound(adjLists[1][u].begin(), adjLists[1][u].end(), v);
            if(lb != adjLists[1][u].end() && *lb == v)
                continue;
            if(d + 1 >= dist[v])
                continue;
            dist[v] = d + 1;
            q.push({d + 1, v});
        }
    }
    ans = max(ans, dist[n - 1]);
    if(ans == INT_MAX) ans = -1;
    cout<<ans<<"\n";
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