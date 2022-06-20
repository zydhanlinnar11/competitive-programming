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

inline void prog(int cs) {
    vs arr(52);
    for(auto &i: arr) cin>>i;

    int i = 26, c = 3, y = 0, ya = 0;
    for(; i>=0 && c; i--, c--) {
        int val = ('2' <= arr[i][0] && arr[i][0] <= '9' ? arr[i][0] - '0' : 10);
        i -= 10 - val;
        ya += 10 - val;
        y += val;
    }
    cout<<"Case "<<cs<<": "<<arr[ya + y + 2]<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/uva/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/uva/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    for(int i=1; i<=t; i++) prog(i);
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}