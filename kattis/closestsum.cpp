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

inline void prog(int c) {
    int n;
    if(scanf("%d", &n) == EOF)
        exit(0);
    printf("Case %d:\n", c);
    vi arr(n);
    for(auto &i: arr)
        cin>>i;
    vi res;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            res.push_back(arr[i] + arr[j]);
    sort(res.begin(), res.end());
    int q; cin>>q;
    for(int i=0; i<q; i++) {
        int m;
        cin>>m;
        int idx = lower_bound(res.begin(), res.end(), m) - res.begin();
        int sz = res.size();
        int ans;
        if(idx == sz || (idx > 0 && abs(m - res[idx]) >= abs(m - res[idx - 1])))
            ans = res[idx - 1];
        else ans = res[idx];
        printf("Closest sum to %d is %d.\n", m, ans);
    }
}

int main() {
    chrono_time_start = system_clock::now();
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/kattis/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/kattis/out", "w", stdout);
    #endif
    // int t = 1;
    // cin>>t;
    for(int i=1; true; i++) {
        prog(i);
    }
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}