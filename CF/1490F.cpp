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
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void prog() {
    int n;
    cin>>n;
    vi arr(n);
    map<int, int> cnt_tmp;
    int mx_occ = 0;
    for(auto &i: arr) {
        cin>>i;
        cnt_tmp[i]++;
        mx_occ = max(mx_occ, cnt_tmp[i]);
    }
    vi cnt;
    for(auto &i: cnt_tmp) {
        cnt.push_back(i.second);
    }
    sort(cnt.begin(), cnt.end());
    vi ps(cnt.size() + 1, 0);
    for(int i=1; i<=(int)cnt.size(); i++) {
        ps[i] = ps[i - 1] + cnt[i - 1];
    }
    int ans = n;
    int ncnt = cnt.size();
    for(int i=0; i<=mx_occ; i++) {
        int removed = 0;
        int idx = lower_bound(cnt.begin(), cnt.end(), i) - cnt.begin();
        removed += ps[idx];
        removed += ps[ncnt] - ps[idx] - (ncnt - idx) * i;
        ans = min(ans, removed);
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