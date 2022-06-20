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

inline void prog() {
    vi pal = {0, 70, 140, 210, 280, 350, 601, 671, 741, 811, 881, 951, 1202, 1272, 1342, 1412};
    set<int> visited;
    int h, m;
    scanf("%d:%d", &h, &m);
    int start = h * 60 + m;
    int interval;
    cin>>interval;
    while(true) {
        start += interval;
        start %= 60 * 24;
        if(visited.find(start) != visited.end()) break;
        visited.insert(start);
    }
    int ans = 0;
    for(auto i: pal) {
        ans += (visited.find(i) != visited.end());
    }
    cout<<ans<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/CF/1692/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/CF/1692/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}