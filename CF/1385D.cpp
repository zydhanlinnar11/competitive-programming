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

ll compute(string &s, int l, int r, char c) {
    if(l == r)
        return s[l] != c;
    if(c > 'z')
        return s.length();
    int len = r - l + 1;
    int mid = l+(len >> 1);
    ll ans = s.length();
    ll fst = 0, scnd = 0;
    for(int j=l; j<mid; j++) {
        fst += s[j] != c;
    }
    for(int j=mid; j<=r; j++) {
        scnd += s[j] != c;
    }
    fst += compute(s, mid, r, c + 1);
    scnd += compute(s, l, mid - 1, c + 1);
    ans = min(ans, min(fst, scnd));
    return ans;
}

inline void prog() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll ans = n;
    for(char c = 'a'; c<='z'; c++) {
        ans = min(ans, compute(s, 0, n - 1, 'a'));
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