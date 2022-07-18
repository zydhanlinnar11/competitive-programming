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

typedef pair<long double, long double> pdd;
typedef vector<pdd> vdd;

inline int prog() {
    int n, d;
    cin>>n>>d;
    if(n == 0 && d == 0)
        exit(0);
    vdd points(n);
    for(auto &point: points)
        cin>>point.first>>point.second;
    set<pdd> byL, byR;
    for(auto &point: points) {
        if(point.second > d) {
            return -1;
        }
        auto [x, y] = point;
        auto l = -sqrt((ll)d*d - y*y) + x;
        auto r = sqrt((ll)d*d - y*y) + x;
        byL.insert({l, r});
        byR.insert({r, l});
    }
    int ans = 0;
    while(!byR.empty()) {
        auto [r, l] = *byR.begin();
        byR.erase(byR.begin());
        byL.erase({l, r});
        while(!byL.empty() && byL.begin()->first <= r) {
            auto [l1, r1] = *byL.begin();
            byL.erase(byL.begin());
            byR.erase({r1, l1});
        }
        ans++;
    }
    return ans;    
}

int main() {
    chrono_time_start = system_clock::now();
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/uva/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/uva/out", "w", stdout);
    #endif
    for(int i=0; true; i++)
        printf("Case %d: %d\n", i + 1, prog());
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}