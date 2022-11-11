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

int movx[] = {0, 0, -1, 1};
int movy[] = {-1, 1, 0, 0};
int h, w;

inline void prog() {
    cin>>h>>w;
    vs grid(h);
    vs visited(h, string(w, '0'));
    for(string &row: grid)
        cin>>row;
    queue<tuple<int, int, char>> q;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(grid[i][j] != 'S')
                continue;
            for(int k=0; k<4; k++) {
                int x = i + movx[k];
                int y = j + movy[k];
                if(x < 0 || y < 0 || x >= h || y >= w || grid[x][y] == '#')
                    continue;
                q.push({x, y, k + 1 + '0'});
                visited[x][y] = k + 1 + '0';
            }
        }
    }
    while(!q.empty()) {
        auto [i, j, clr] = q.front();
        q.pop();
        for(int k=0; k<4; k++) {
            int x = i + movx[k];
            int y = j + movy[k];
            if(x < 0 || y < 0 || x >= h || y >= w || grid[x][y] == '#')
                continue;
            if(visited[x][y] == visited[i][j] || grid[x][y] == 'S')
                continue;
            if(visited[x][y] == '0') {
                visited[x][y] = clr;
                q.push({x, y, clr});
            } else {
                cout<<"Yes\n";
                return;
            }
        }
    }
    cout<<"No"<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/Atcoder/abc276/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/Atcoder/abc276/out", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}