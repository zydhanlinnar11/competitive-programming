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
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vi> vi2d;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline bool check(vector<ll> &arr, ll k, ll h) {
    ll res = k;
    for(int i=(int)arr.size() - 2; i>= 0; i--) {
        res += min(k, arr[i + 1] - arr[i]);
    }
    return res >= h;
}

inline void prog() {
    ll n, h;
    cin>>n>>h;
    vector<ll> arr(n);
    for(auto &i: arr) cin>>i;
    // cout<<check(arr, 470, h)<<"\n";
    ll l = 1, r = 1e18;
    while(l < r) {
        ll mid = (l + r) / 2;
        if(!check(arr, mid, h))
            l = mid + 1;
        else r = mid;
    }
    cout<<(l + r) / 2<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/CP/CF/in", "r", stdin);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}