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

inline void prog() {
    int n;
    cin>>n;
    vl arr(n);
    for(auto &i: arr) cin>>i;
    vl prefsum(n+1, 0);
    for(int i=1; i<=n; i++) {
        prefsum[i] = prefsum[i - 1];
        prefsum[i] += arr[i - 1];
    }
    int globmin = INT_MAX;
    for(int first_seg_len=1; first_seg_len<=n; first_seg_len++) {
        ll sum = prefsum[first_seg_len];
        int l = first_seg_len + 1;
        int r = l;
        bool skip = false;
        int locmin = first_seg_len;
        for(; r <= n; r++) {
            ll segsum = prefsum[r] - prefsum[l - 1];
            if(segsum == sum) {
                locmin = max(locmin, r - l + 1);
                l = r + 1;
                continue;
            }
            if(segsum > sum || r == n) {
                skip = true;
                break;
            }
        }
        if(skip) continue;
        globmin = min(globmin, locmin);
    }
    cout<<globmin<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/CF/1741/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/CF/1741/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}