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
typedef vector<ll> vl;
typedef vector<vl> vl2d;
typedef vector<string> vs;
typedef vector<vs> vs2d;
typedef vector<pii> vii;
typedef vector<pll> vll;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void prog() {
    int n; cin>>n;
    vii arr(n);
    for(auto &i: arr) {
        cin>>i.first>>i.second;
        i.first--;
        i.second--;
    }
    vi2d mapper(n);
    vi2d adjList(n);
    for(int i=0; i<n; i++) {
        auto &[a, b] = arr[i];
        mapper[a].push_back(i);
        mapper[b].push_back(i);
        if(a == b || mapper[a].size() > 2U || mapper[b].size() > 2U) {
            cout<<"NO\n";
            return;
        }
        for(int j=0; j<(int)mapper[a].size()-1; j++) {
            adjList[i].push_back(mapper[a][j]);
            adjList[mapper[a][j]].push_back(i);
        }
        for(int j=0; j<(int)mapper[b].size()-1; j++) {
            if(count(mapper[a].begin(), mapper[a].end(), mapper[b][j]) >= 1)
                continue;
            adjList[i].push_back(mapper[b][j]);
            adjList[mapper[b][j]].push_back(i);
        }
    }
    vi colors(n, -1);
    for(int i=0; i<n; i++) {
        if(colors[i] != -1)
            continue;
        queue<int> q;
        q.push(i);
        colors[i] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            auto clr = colors[u] ^ 1;
            for(auto &v: adjList[u]) {
                if(colors[v] != -1 && colors[v] != clr) {
                    cout<<"NO\n";
                    return;
                }
                if(colors[v] != -1)
                    continue;
                colors[v] = clr;
                q.push(v);
            }
        }
    }
    cout<<"YES"<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/CF/1702/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/CF/1702/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}