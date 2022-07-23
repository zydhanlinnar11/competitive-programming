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

typedef vector<vii> vvii;

inline void prog() {
    int n;
    cin>>n;
    vi avail;
    vvi adjMat(n, vi(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>adjMat[i][j];
        }
    }
    vl ans(n);
    vl e(n);
    for(int i=0; i<n; i++)
        cin>>e[i];
    vvl dist(n, vl(n, INT64_MAX));
    for(int i=n-1; i>=0; i--) {
        int erased = e[i];
        erased--;
        avail.push_back(erased);
        ll sum = 0;
        priority_queue<pair<ll, int>> pq;
        pq.push({0, erased});
        dist[erased][erased] = 0;
        while(!pq.empty()) {
            auto [l, u] = pq.top();
            l = -l;
            pq.pop();
            for(auto &v: avail) {
                ll w = adjMat[u][v];
                if(l + w >= dist[erased][v])
                    continue;
                dist[erased][v] = l + w;
                pq.push({-l - w, v});
            }
        }
        for(auto &u: avail) {
            for(auto &v: avail) {
                if(v == erased) continue;
                dist[u][erased] = min(dist[u][erased], dist[u][v] + adjMat[v][erased]);
            }
            for(auto &v: avail) {
                auto mn = min(dist[u][v], dist[u][erased] + dist[erased][v]);
                sum += mn;
                dist[u][v] = mn;
            }
        }
        ans[i] = sum;
    }
    for(int i=0; i<n; i++)
        cout<<ans[i]<<" \n"[i == n - 1];
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