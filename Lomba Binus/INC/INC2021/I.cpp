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

inline ll dijkstra(vector<pair<ll, pair<ll, ll>>> adjList[], ll n) {
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    vector<ll> shortestPath(n, INT64_MAX);
    pq.push(mp(0, mp(0, 1)));
    while(!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        auto currPos = curr.second.first;
        auto currId = curr.second.second;
        auto currDist = curr.first;
        if(currPos == n - 1) {
            return currDist;
        }
        for(unsigned i=0; i<adjList[currPos].size(); i++) {
            auto dest = adjList[currPos][i];
            auto destPos = dest.second.first;
            auto destId = dest.second.second;
            auto destDist = dest.first;
            auto totalDist = currDist + destDist + (ll)abs(destId - currId);
            if(destPos == n - 1)
                totalDist += (ll)abs(destId - 1);
            pq.push(mp(totalDist, mp(destPos, destId)));
            shortestPath[destPos] = totalDist;
        }
    }
    return INT64_MAX;
}

inline void prog() {
    ll n, m;
    cin>>n>>m;
    vector<pair<ll, pair<ll, ll>>> adjList[n];
    for(int i=0; i<m; i++) {
        ll u, v, p, t;
        cin>>u>>v>>p>>t;
        u--, v--;
        adjList[u].push_back(mp(t, mp(v, p)));
        adjList[v].push_back(mp(t, mp(u, p)));
    }
    cout<<dijkstra(adjList, n)<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/CP/CF/in", "r", stdin);
    #endif
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}