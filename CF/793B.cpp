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
typedef tuple<int, pii, int> piiii;

inline void prog() {
    int n, m;
    cin>>n>>m;
    vs arr(n);
    pii st, office;
    for(int i=0; i<n; i++) {
        auto &s = arr[i];
        cin>>s;
        auto sPos = s.find('S');
        auto tPos = s.find('T');
        if(sPos != string::npos)
            st = {i, sPos};
        if(tPos != string::npos)
            office = {i, tPos};
    }
    vii directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vvi dist(n, vi(m, INT_MAX));
    // d, u, direction
    priority_queue<piiii> q;
    for(int i=0; i<4; i++) {
        q.push({0, st, i});
        auto &[x, y] = st;
        dist[x][y] = 0;
    }
    while(!q.empty()) {
        auto [d, u, dir] = q.top();
        d = -d;
        q.pop();
        if(u == office) {
            break;
        }
        for(int i=0; i<4; i++) {
            auto &[x, y] = directions[i];
            pii v = {u.first + x, u.second + y};
            if(v.first < 0 || v.first >= n || v.second < 0 || v.second >= m)
                continue;
            if(arr[v.first][v.second] == '*')
                continue;
            int w = (i != dir ? 1 : 0);
            if(w + d > dist[v.first][v.second] || w + d > 2)
                continue;
            dist[v.first][v.second] = w + d;
            q.push({-w - d, v, i});
        }
    }
    cout<<(dist[office.first][office.second] <= 2 ? "YES" : "NO")<<"\n";
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