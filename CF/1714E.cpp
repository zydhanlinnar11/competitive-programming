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
    for(auto &i: arr)
        cin>>i;
    for(int i=0; i<n; i++)
        if(arr[i] & 1) {
            arr[i] += (arr[i] % 10);
        }
    ll mn = *min_element(arr.begin(), arr.end());
    ll mx = *max_element(arr.begin(), arr.end());
    if(mn == mx) {
        cout<<"YES\n";
        return;
    }
    
    for(int i=0; i<n; i++)
        if(arr[i] % 10 == 0) {
            cout<<"NO\n";
            return;
        }
    vvl inc(4);
    for(int i=1; i<=4; i++) {
        int x = i * 2;
        for(int j=1; j<=4; j++) {
            inc[i - 1].push_back(x);
            x = (x + (x % 10)) % 10;
        }
    }
    for(int i=0; i<n; i++) {
        auto tgt = INT64_MAX - arr[i];
        auto tmp = tgt / 20 * 20;
        int lstTmp = ((arr[i] % 10) / 2) - 1;
        tmp += arr[i];
        for(int j=0; j<4 && INT64_MAX - inc[lstTmp][j] >= tmp; j++) {
            tmp += inc[lstTmp][j];
        }
        arr[i] = tmp;
    }
    if(*min_element(arr.begin(), arr.end()) == *max_element(arr.begin(), arr.end()))
        cout<<"YES\n";
    else cout<<"NO\n";
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