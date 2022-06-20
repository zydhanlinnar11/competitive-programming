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
typedef vector<ll> vll;
typedef vector<vll> vll2d;
typedef vector<string> vs;
typedef vector<vs> vs2d;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

int find(vi &par, int u) {
    if(par[u] == u) return u;
    return par[u] = find(par, par[u]);
}

void join(vi &par, int u, int v) { par[find(par, u)] = par[find(par, v)]; }

inline void prog() {
    int n, m1, m2;
    cin>>n>>m1>>m2;
    vi par1(n), par2(n);
    iota(par1.begin(), par1.end(), 0);
    iota(par2.begin(), par2.end(), 0);
    for(int i=0; i<m1; i++) {
        int u, v; cin>>u>>v; u--, v--;
        join(par1, u, v);
    }
    for(int i=0; i<m2; i++) {
        int u, v; cin>>u>>v; u--, v--;
        join(par2, u, v);
    }
    vector<pii> ans;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int parU1 = find(par1, i);
            int parV1 = find(par1, j);
            int parU2 = find(par2, i);
            int parV2 = find(par2, j);
            if(parU1 == parV1 || parU2 == parV2) continue;
            join(par1, i, j);
            join(par2, i, j);
            ans.push_back({i + 1, j + 1});
        }
    }
    cout<<ans.size()<<"\n";
    for(auto &i: ans) cout<<i.first<<" "<<i.second<<"\n";
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