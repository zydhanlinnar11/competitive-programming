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
typedef pair<ll, pll> plll;
typedef vector<plll> vlll;

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void prog() {
    int n; cin>>n;
    vl arr(n);
    for(auto &i: arr) cin>>i;
    // cnt, sum, minval
    vlll a1(n), a2(n);
    a1[0] = {1, {arr[0], arr[0]}};
    for(int i=1; i<n; i++) {
        a1[i] = a1[i - 1];
        if(!(i & 1)) {
            a1[i].first++;
            a1[i].second.first += arr[i];
            a1[i].second.second = min(a1[i].second.second, arr[i]);
        }
    }
    a2[1] = {1, {arr[1], arr[1]}};
    for(int i=2; i<n; i++) {
        a2[i] = a2[i - 1];
        if(i & 1) {
            a2[i].first++;
            a2[i].second.first += arr[i];
            a2[i].second.second = min(a2[i].second.second, arr[i]);
        }
    }
    ll ans = INT64_MAX;
    for(int i=1; i<n; i++) {
        auto s1 = (a1[i].second.first - a1[i].second.second) + (a1[i].second.second * (n - a1[i].first + 1));
        auto s2 = (a2[i].second.first - a2[i].second.second) + (a2[i].second.second * (n - a2[i].first + 1));
        ans = min(ans, s1 + s2);
    }
    cout<<ans<<"\n";
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
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}