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
    int n;
    cin>>n;
    vi arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int r1, c1, r2, c2;
    cin>>r1>>c1>>r2>>c2;
    r1--, c1--, r2--, c2--;
    vvi dist(n);
    for(int i=0; i<n; i++) {
        dist[i] = vi(arr[i] + 1, INT_MAX);
    }
    queue<piii> q;
    q.push({0, r1, c1});
    dist[r1][c1] = 0;
    while(!q.empty()) {
        auto [l, r, c] = q.front();
        q.pop();
        if(r == r2 && c == c2) {
            cout<<l<<"\n";
            return;
        }
        // right
        if(c < arr[r] && l + 1 < dist[r][c + 1]) {
            dist[r][c + 1] = l + 1;
            q.push({l + 1, r, c + 1}); 
        }
        // left
        if(c > 0 && l + 1 < dist[r][c - 1]) {
            dist[r][c - 1] = l + 1;
            q.push({l + 1, r, c - 1});
        }
        // up
        if(r > 0 && l + 1 < dist[r - 1][min(c, arr[r - 1])]) {
            dist[r - 1][min(c, arr[r - 1])] = l + 1;
            q.push({l + 1, r - 1, min(c, arr[r - 1])});
        }
        // down
        if(r < n - 1 && l + 1 < dist[r + 1][min(c, arr[r + 1])]) {
            dist[r + 1][min(c, arr[r + 1])] = l + 1;
            q.push({l + 1, r + 1, min(c, arr[r + 1])});
        }
    }
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