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
typedef vector<bool> vb;
typedef vector<vb> vvb;

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

ll dfs1(int n, int m, vs &arr, vii &directions, vvi &cnt, vvb &visited, int i, int j) {
    visited[i][j] = true;
    ll ans = cnt[i][j];
    for(auto &[x, y]: directions) {
        int dx = i + x;
        int dy = j + y;
        if(dx < 0 || dx >= n || dy < 0 || dy >= m || arr[dx][dy] == '*'
            || visited[dx][dy])
            continue;
        ans += dfs1(n, m, arr, directions, cnt, visited, dx, dy);
    }
    return ans;
}

void dfs2(int n, int m, vs &arr, vii &directions, vvl &dp, vvb &visited, int i, int j, ll val) {
    visited[i][j] = true;
    dp[i][j] = val;
    for(auto &[x, y]: directions) {
        int dx = i + x;
        int dy = j + y;
        if(dx < 0 || dx >= n || dy < 0 || dy >= m || arr[dx][dy] == '*'
            || visited[dx][dy])
            continue;
        dfs2(n, m, arr, directions, dp, visited, dx, dy, val);
    }
}

inline void prog() {
    int n, m, k;
    cin>>n>>m>>k;
    vs arr(n);
    for(auto &s: arr) cin>>s;
    vii directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vvi cnt(n, vi(m, 0));
    vvb v1(n, vb(m, false)), v2(n, vb(m, false));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j] == '.')
                continue;
            for(auto &[x, y]: directions) {
                int dx = i + x;
                int dy = j + y;
                if(dx < 0 || dx >= n || dy < 0 || dy >= m || arr[dx][dy] == '*')
                    continue;
                cnt[dx][dy]++;
            }
        }
    }
    vvl dp(n, vl(m, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(v1[i][j] || arr[i][j] == '*') continue;
            auto val = dfs1(n, m, arr, directions, cnt, v1, i, j);
            dfs2(n, m, arr, directions, dp, v2, i, j, val);
        }
    }
    while(k--) {
        int a, b;
        cin>>a>>b;
        a--, b--;
        cout<<dp[a][b]<<"\n";
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