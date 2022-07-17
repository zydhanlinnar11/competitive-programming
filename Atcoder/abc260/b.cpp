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

typedef pair<pii, int> piii;
typedef vector<piii> viii;

inline void prog() {
    int n, x, y, z;
    cin>>n>>x>>y>>z;
    viii arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i].first.first;
        arr[i].second = i;
    }
    for(int i=0; i<n; i++) {
        cin>>arr[i].first.second;
    }
    vi ans;
    sort(arr.begin(), arr.end(), [](piii a, piii b) {
        if(a.first.first == b.first.first)
            return a.second < b.second;
        return a.first.first > b.first.first;
    });
    for(int i=0; i<x; i++) {
        ans.push_back(arr.begin()->second);
        arr.erase(arr.begin());
    }
    sort(arr.begin(), arr.end(), [](piii a, piii b) {
        if(a.first.second == b.first.second)
            return a.second < b.second;
        return a.first.second > b.first.second;
    });
    for(int i=0; i<y; i++) {
        ans.push_back(arr.begin()->second);
        arr.erase(arr.begin());
    }
    sort(arr.begin(), arr.end(), [](piii a, piii b) {
        if(a.first.second + a.first.first == b.first.second + b.first.first)
            return a.second < b.second;
        return a.first.second + a.first.first > b.first.second + b.first.first;
    });
    for(int i=0; i<z; i++) {
        ans.push_back(arr.begin()->second);
        arr.erase(arr.begin());
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<x+y+z; i++)
        cout<<ans[i] + 1<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/Atcoder/abc260/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/Atcoder/abc260/out", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}