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

typedef tuple<int, int, int> piii;

inline void prog() {
    int n, m;
    cin>>n>>m;
    queue<piii> q;
    vvi dist(n, vi(m, 2e5));
    int k; cin>>k;
    for(int i=0; i<k; i++) {
        int x, y;
        cin>>x>>y;
        x--, y--;
        q.push({x, y, 0});
        dist[x][y] = 0;
    }
    vii steps = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    while(!q.empty()) {
        auto [x, y, d] = q.front();
        q.pop();
        for(auto &[i, j]: steps) {
            auto xd = x + i;
            auto yd = y + j;
            auto dd = d + 1;
            if(xd < 0 || xd >= n || yd < 0 || yd >= m || dd >= dist[xd][yd])
                continue;
            dist[xd][yd] = dd;
            q.push({xd, yd, dd});
        }
    }
    pii ans = {0, 0};
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            auto [x, y] = ans;
            if(dist[i][j] > dist[x][y]) {
                ans = {i, j};
            }
        }
    }
    cout<<ans.first + 1<<" "<<ans.second + 1<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/CF/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/CF/out", "w", stdout);
    #else
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}