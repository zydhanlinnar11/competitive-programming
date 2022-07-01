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

// inline int find(vi &par, int x) {
//     if(par[x] == x) return x;
//     return (par[x] = find(par, par[x]));
// }

// inline void join(vi &par, vi &rank, int u, int v) {
//     int parU = find(par, u);
//     int parV = find(par, v);
//     if(parU == parV) return;
//     if(rank[parU] < rank[parV]) swap(parU, parV);
//     rank[parU] += rank[parV];
// }
typedef vector<bool> vb;

inline int countChild(vi2d &adjList, vb &visited, vi &childCount, vi2d &children, int n, int u) {
    visited[u] = true;
    if(adjList[u].size() == 1 && visited[adjList[u].front()]) {
        childCount[u] = 0;
        return childCount[u];
    }
    for(auto &v: adjList[u]) {
        if(visited[v]) continue;
        children[u].push_back(v);
        childCount[u] += 1 + countChild(adjList, visited, childCount, children, n, v);
    }
    return childCount[u];
}

inline int getAns(vi2d &children, vi &childCount, int n, int u) {
    if(children[u].size() == 0) return 0;
    if(children[u].size() == 1) return childCount[children[u][0]];
    return max(
        childCount[children[u][0]] + getAns(children, childCount, n, children[u][1]),
        childCount[children[u][1]] + getAns(children, childCount, n, children[u][0])
    );
}

inline void prog() {
    int n; cin>>n;
    vi2d adjList(n + 1), children(n + 1);
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vb visited(n + 1, false);
    vi childCount(n + 1, 0);
    countChild(adjList, visited, childCount, children, n, 1);
    int ans = getAns(children, childCount, n, 1);
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
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}