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

void bfs(queue<pii> &q, vi &dist, vvi &adjList) {
    while(!q.empty()) {
        auto [l, u] = q.front();
        q.pop();
        for(auto &v: adjList[u]) {
            if(l + 1 >= dist[v])
                continue;
            dist[v] = l + 1;
            q.push({l + 1, v});
        }
    }
}

inline void prog() {
    int n, k;
    cin>>n>>k;
    vi friends(k);
    for(auto &fr: friends) {
        cin>>fr;
        fr--;
    }
    vvi adjList(n);
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vvi dist(2, vi(n, INT_MAX));
    queue<pii> q;
    dist[0][0] = 0;
    q.push({0, 0});
    bfs(q, dist[0], adjList);
    for(int &fr: friends) {
        q.push({0, fr});
        dist[1][fr] = 0;
    }
    bfs(q, dist[1], adjList);
    for(int i=1; i<n; i++) {
        if(adjList[i].size() > 1U)
            continue;
        if(dist[0][i] < dist[1][i]) {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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