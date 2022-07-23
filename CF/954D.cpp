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

vector<int> bfs(const int n, const int s, vvi &adjList) {
    vi dist(n, INT_MAX);
    queue<pii> q;
    dist[s] = 0;
    q.push({0, s});
    while(!q.empty()) {
        auto [d, u] = q.front();
        q.pop();
        for(auto &v: adjList[u]) {
            auto w = d + 1;
            if(w >= dist[v])
                continue;
            dist[v] = w;
            q.push({w, v});
        }
    }
    return dist;
}

inline void prog() {
    int n, m, s, t;
    cin>>n>>m>>s>>t;
    s--, t--;
    vvi adjList(n);
    for(int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    auto distS = bfs(n, s, adjList);
    auto distT = bfs(n, t, adjList);
    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(distS[i] + distT[j] + 1 < distS[t]
            || distS[j] + distT[i] + 1 < distS[t])
                ans++;
        }
    }
    cout<<n * (n - 1) / 2 - m - ans<<"\n";
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