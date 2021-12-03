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
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vi> vi2d;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void prog() {
    int n, k, u, v, ans = 0;
    cin>>n>>k;
    vi deg(n, 0);
    set<int> adjList[n];
    for(int i=0; i<n-1; i++) {
        cin>>u>>v;
        u--, v--;
        deg[u]++, deg[v]++;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
    queue<pii> q;
    for(int j=0; j<n; j++) {
        if(deg[j] == 1 || deg[j] == 0) {
            q.push(mp(j, 1));
        }
    }
    while(!q.empty()) {
        pii curr = q.front();
        q.pop();
        deg[curr.first] = -1;
        ans++;

        int nxt = *adjList[curr.first].begin();
        adjList[nxt].erase(curr.first);
        deg[nxt]--;
        if(deg[nxt] != 1) continue;
        if(curr.second == k) continue;
        q.push(mp(nxt, curr.second + 1));
    }
    cout<<n - ans<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/CP/CF/in", "r", stdin);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}