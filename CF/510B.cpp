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

int n, m, sX, sY;

void dfs(bool &ans, map<pii, vector<pii>> &adjList, vi2d &color, int posY, int posX, int befY, int befX) {
    if (color[posY][posX] == 2) {
        return;
    }

    if (color[posY][posX] == 1 && sY == posY && sX == posX) {
        ans |= true;
        return;
    }

    if (color[posY][posX] == 1) return;

    if (color[posY][posX] == 0) {
        color[posY][posX] = 1;
    }

    for(pii next: adjList[mp(posY, posX)]) {
        if(next.first == befY && next.second == befX) continue;
        dfs(ans, adjList, color, next.first, next.second, posY, posX);
    }
    color[posY][posX] = 2;
}

inline void prog() {
    cin>>n>>m;
    vs arr(n);
    map<pii, vector<pii>> adjList;
    vi2d color(n, vi(m, 0));
    for(auto &i: arr) cin>>i;
    for(int i=n - 1; i>=0; i--) {
        for(int j=m - 1;j>=0; j--) {
            if(i > 0 && arr[i - 1][j] == arr[i][j]) {
                adjList[mp(i, j)].push_back(mp(i - 1, j));
                adjList[mp(i - 1, j)].push_back(mp(i, j));
            }
            if(j > 0 && arr[i][j - 1] == arr[i][j]) {
                adjList[mp(i, j)].push_back(mp(i, j - 1));
                adjList[mp(i, j - 1)].push_back(mp(i, j));
            }
        }
    }
    
    bool ans = false;
    for(int i=0; i<n && !ans; i++) {
        for(int j=0; j<m && !ans; j++) {
            color = vi2d(n, vi(m, 0));
            if (color[i][j] == 2) continue;
            sY = i, sX = j;
            dfs(ans, adjList, color, i, j, -1, -1);
        }
    }
    cout<<(ans ? "Yes" : "No")<<"\n";
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