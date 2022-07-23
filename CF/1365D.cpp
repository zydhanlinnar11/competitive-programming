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

typedef tuple<int, pii> piii;

inline void prog() {
    int n, m;
    cin>>n>>m;
    vs arr(n);
    for(auto &i: arr)
        cin>>i;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j] != 'B')
                continue;
            if(i > 0 && arr[i - 1][j] == '.')
                arr[i - 1][j] = '#';
            if(i < n - 1 && arr[i + 1][j] == '.')
                arr[i + 1][j] = '#';
            if(j > 0 && arr[i][j - 1] == '.')
                arr[i][j - 1] = '#';
            if(j < m - 1 && arr[i][j + 1] == '.')
                arr[i][j + 1] = '#';
        }
    }
    vvi dist(n, vi(m, INT_MAX));
    queue<piii> q;
    if(arr[n - 1][m - 1] != '#') {
        q.push({0, {n - 1, m - 1}});
        dist[n - 1][m - 1] = 0;
    }
    vii directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    while(!q.empty()) {
        auto [l, u] = q.front();
        q.pop();
        for(auto &[i, j]: directions) {
            pii v = {u.first + i, u.second + j};
            if(v.first < 0 || v.first >= n || v.second < 0 || v.second >= m)
                continue;
            if(l + 1 >= dist[v.first][v.second] || arr[v.first][v.second] == '#')
                continue;
            dist[v.first][v.second] = l + 1;
            q.push({l + 1, v});
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if((arr[i][j] == 'B' && dist[i][j] != INT_MAX)
                || (arr[i][j] == 'G' && dist[i][j] == INT_MAX)) {
                    cout<<"NO\n";
                    return;
                }
        }
    }
    cout<<"YES\n";
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