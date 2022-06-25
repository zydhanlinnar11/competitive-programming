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
typedef vector<ll> vll;
typedef vector<vll> vll2d;
typedef vector<string> vs;
typedef vector<vs> vs2d;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline int getRes(vi &adult, vi&child, int x) {
    int fx = (int)(lower_bound(child.begin(), child.end(), x) - child.begin());
    fx += adult.size() - (int)(lower_bound(adult.begin(), adult.end(), x) - adult.begin());
    
    return fx;
}

inline void prog() {
    int n; cin>>n;
    string s; cin>>s;
    vi arr(n), adult, child;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        if(s[i] == '0') child.push_back(arr[i]);
        else adult.push_back(arr[i]);
    }
    sort(arr.begin(), arr.end());
    sort(adult.begin(), adult.end());
    sort(child.begin(), child.end());
    int ans = 0;
    for(int i=0; i<n; i++) {
        int x = arr[i];
        ans = max(ans, getRes(adult, child, x));
    }
    ans = max(ans, getRes(adult, child, arr.back() + 1));
    cout<<ans<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/Atcoder/abc257/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/Atcoder/abc257/out", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}