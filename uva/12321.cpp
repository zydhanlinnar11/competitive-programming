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
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<vl> vl2d;
typedef vector<pl> vll; 
typedef vector<string> vs;
typedef vector<vs> vs2d;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void prog() {
    ll L; cin>>L;
    int G; cin>>G;
    if(L == G && G == 0) exit(0);
    vll stations(G);
    for(auto &station: stations) {
        ll x, r; cin>>x>>r;
        station = {x - r, x + r};
    }
    sort(stations.begin(), stations.end(), [](const pl &a, const pl &b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });
    int ans = 0;
    ll covered = 0;
    bool possible = true;
    for(int i=0; i<G && possible; i++) {
        if(covered >= L) break;
        if(stations[i].first > covered) {
            possible = false;
            break;
        }
        if(stations[i].second <= covered) continue;
        int lgIdx = i;
        for(int j=i+1; j<G && stations[j].first <= covered; j++) {
            if(stations[lgIdx].second < stations[j].second)
                lgIdx = j;
        }
        ans++;
        covered = stations[lgIdx].second;
        i = lgIdx;
    }
    if(!possible || covered < L) cout<<"-1\n";
    else cout<<G - ans<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/uva/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/uva/out", "w", stdout);
    #endif
    // int t = 1;
    // cin>>t;
    while(true) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}