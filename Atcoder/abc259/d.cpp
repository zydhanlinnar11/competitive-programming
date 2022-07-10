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
typedef pair<pll, ll> plll;
typedef vector<plll> vlll;
typedef vector<pll> vll;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void prog() {
    int n; 
    cin>>n;
    ll sx, sy, tx, ty;
    cin>>sx>>sy>>tx>>ty;
    vlll circles(n);
    for(int i=0; i<n; i++) {
        cin>>circles[i].first.first>>circles[i].first.second>>circles[i].second;
    }
    vi starts, finishes;
    for(int i=0; i<n; i++) {
        auto [coord, r] = circles[i];
        auto [x, y] = coord;
        if((sx - x) * (sx - x) + (sy - y) * (sy - y) == r * r) {
            starts.push_back(i);
        }
    }
    for(int i=0; i<n; i++) {
        auto [coord, r] = circles[i];
        auto [x, y] = coord;
        if((tx - x) * (tx - x) + (ty - y) * (ty - y) == r * r) {
            finishes.push_back(i);
        }
    }
    vi2d adjList(n);
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            ll diff = circles[i].second - circles[j].second;
            ll plus = circles[i].second + circles[j].second;
            ll dx = circles[i].first.first - circles[j].first.first;
            ll dy = circles[i].first.second - circles[j].first.second;
            ll pyt = dx*dx + dy*dy;
            if(diff*diff <= pyt && pyt <= plus*plus) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    for(int start: starts) {
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            for(auto v: adjList[top]) {
                if(visited[v]) continue;
                visited[v] = true;
                q.push(v);
            }
        }
        for (int finish: finishes) {
            if(visited[finish]) {
                cout<<"Yes\n";
                return;
            }
        }
    }
    cout<<"No\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/Atcoder/abc259/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/Atcoder/abc259/out", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}