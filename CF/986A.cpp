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
    int n, m, k, s;
    cin>>n>>m>>k>>s;
    vvi typeTowns(k);
    for(int i=0; i<n; i++) {
        int type;
        cin>>type;
        typeTowns[type - 1].push_back(i);
    }
    vvi adjList(n);
    for(int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vvi ans(n);
    for(int i=0; i<k; i++) {
        queue<pii> q;
        vi dist(n, INT_MAX);
        for(int &u: typeTowns[i]) {
            q.push({0, u});
            dist[u] = 0;
        }
        while(!q.empty()) {
            auto [d, u] = q.front();
            q.pop();
            for(auto &v: adjList[u]) {
                if(d + 1 >= dist[v])
                    continue;
                dist[v] = d + 1;
                q.push({d + 1, v});
            }
        }
        for(int j=0; j<n; j++) {
            ans[j].push_back(dist[j]);
        }
    }
    for(int i=0; i<n; i++) {
        sort(ans[i].begin(), ans[i].end());
        int sum = 0;
        for(int j=0; j<s; j++)
            sum += ans[i][j];
        cout<<sum<<" \n"[i == n - 1];
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
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}