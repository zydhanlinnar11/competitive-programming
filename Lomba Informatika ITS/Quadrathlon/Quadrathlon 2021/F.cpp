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

vector<map<ll, ll>> memo(101);
vector<map<ll, bool>> computed(101);

inline ll solve(ll i, ll c, vector<ll> &w, vector<ll> &v) {
    if(i == 0) return 0;
    if(computed[i][c]) return memo[i][c];

    ll ans = solve(i - 1, c, w, v);
    if(c >= w[i]) {
        ans = max(ans, solve(i - 1, c - w[i], w, v) + v[i]);
    }
    computed[i][c] = true;
    memo[i][c] = ans;
    return ans;
}

inline void prog() {
    int n, W;
    cin>>n>>W;
    vector<ll> w(n+1), v(n+1);
    for(int i=1; i<=n; i++) {
        cin>>w[i]>>v[i];
        // if(i > 0) w[i] -= w[0];
    }
    // w[0] = 0;
    cout<<solve(n, W, w, v)<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/CP/CF/in", "r", stdin);
    #endif
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}