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
    string s; cin>>s;
    s = "." + s + ".";
    vl ps1(n + 2, 0), cnt1(n + 2, 0);
    for(int i=1; i<(int)ps1.size(); i++) {
        ps1[i] = ps1[i - 1] + (s[i] == '.' ? cnt1[i - 1] : 0);
        cnt1[i] = cnt1[i - 1] + (s[i] == '*');
    }
    vl ps2(n + 2, 0), cnt2(n + 2, 0);
    for(int i=(int)ps2.size() - 2; i>=0; i--) {
        ps2[i] = ps2[i + 1] + (s[i] == '.' ? cnt2[i + 1] : 0);
        cnt2[i] = cnt2[i + 1] + (s[i] == '*');
    }
    ll ans = INT64_MAX;
    for(int i=1; i<(int)s.size() - 1; i++) {
        ll l = ps1[i - 1], r = ps2[i + 1];
        ll add = (s[i] == '.' ? min(cnt1[i - 1], cnt2[i + 1]) : 0);
        ans = min(ans, l + r + add);
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