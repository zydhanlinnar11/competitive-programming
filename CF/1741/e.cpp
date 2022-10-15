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
typedef vector<vii> vvii;
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
    int n;
    cin>>n;
    vl arr(n);
    for(auto &i: arr) cin>>i;
    vvi adjList(n+1);
    for(int i=0; i<n; i++) {
        if(i + arr[i] < n) {
            adjList[i].push_back(i + arr[i] + 1);
        }
        
        if(i - arr[i] >= 0) {
            adjList[i - arr[i]].push_back(i + 1);
        }
    }
    queue<int> q;
    vb visited(n+1, false);
    visited[0] = true;
    q.push(0);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto &v: adjList[u]) {
            if(visited[v]) continue;
            visited[v] = true;
            q.push(v);
        }
    }
    cout<<(visited.back() ? "YES\n" : "NO\n");
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/CF/1741/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/CF/1741/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}