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

inline vi count(vi2d &res, vi &counted, vi2d &children, int n) {
    if(counted.at(n)) return res.at(n);
    vi &ans = res.at(n);
    for(int child: children.at(n)) {
        auto childRes = count(res, counted, children, child);
        ans.at(0) += childRes.at(0);
        ans.at(1) += childRes.at(1);
    }
    counted.at(n) = true;
    return ans;
}

inline void prog() {
    int n; cin>>n;
    vi par(n + 1);
    vi2d children(n + 1);
    vi counted(n + 1, false);
    // 0 = black, 1 = white
    vi2d res(n + 1, {0, 0});
    for(int i=2; i<=n; i++) {
        cin>>par[i];
        children[par[i]].push_back(i);
    }
    string s; cin>>s;
    int ans = 0;
    for(int i=1; i<=n; i++) res[i][s[i - 1] == 'W']++;
    for(int i=1; i<=n; i++) {
        auto cnt = count(res, counted, children, i);
        ans += (cnt.at(0) == cnt.at(1));
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