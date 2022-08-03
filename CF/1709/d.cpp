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

vl lg(2e5+1);

inline ll getMax(vvl &sparse_table, ll l, ll r) {
    l--, r--;
    ll j = lg[r - l + 1];
    return max(sparse_table[l][j], sparse_table[r - (1 << j) + 1][j]);
}

inline void prog() {
    lg[1] = 0;
    for(ll i=2; i<=2e5; i++)
        lg[i] = lg[i >> 1] + 1;
    ll n, m;
    cin>>n>>m;
    vl columns(m);
    for(auto &col: columns)
        cin>>col;
    vvl sparse_table(m, vl(25));
    for(ll i=0; i<m; i++)
        sparse_table[i][0] = columns[i];
    for(ll i=1; i<25; i++) {
        for(ll j=0; j + (1 << i) <= m; j++) {
            sparse_table[j][i] = max(sparse_table[j][i - 1], sparse_table[j + (1 << (i - 1))][i - 1]);
        }
    }
    int q;
    cin>>q;
    while(q--) {
        ll xs, ys, xf, yf, k;
        cin>>xs>>ys>>xf>>yf>>k;
        if(abs(yf - ys) % k != 0) {
            cout<<"NO\n";
            continue;
        }
        auto mx = getMax(sparse_table, min(ys, yf), max(ys, yf));
        if(mx == n) {
            cout<<"NO\n";
            continue;
        }
        bool can = false;
        can |= (mx < xs && mx < xf && abs(xs - xf) % k == 0);
        can |= (mx < xs && mx >= xf && (xs - xf) % k == 0);
        can |= (mx >= xs && mx < xf && (xf - xs) % k == 0);
        can |= (mx >= xs && mx >= xf && abs(xs - xf) % k == 0 && ((n - xs) / k - (mx - xs) / k) > 0 && ((n - xf) / k - (mx - xf) / k) > 0);
        cout<<(can ? "YES" : "NO")<<"\n";
    }
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/CF/1709/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/CF/1709/out", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}