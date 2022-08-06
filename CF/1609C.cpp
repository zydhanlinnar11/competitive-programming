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

bool isPrime(ll n) {
    if(n <= 1) return false;
    if(n == 2) return true;
    for(ll i=2; i*i<=n; i++)
        if(n % i == 0) return false;
    return true;
}

inline void prog() {
    ll n, e;
    cin>>n>>e;
    vvl arr(e);
    map<ll, bool> prime;
    for(int i=0; i<n; i++) {
        ll tmp;
        cin>>tmp;
        arr[i % e].push_back(tmp);
        if(prime.find(tmp) == prime.end())
            prime[tmp] = isPrime(tmp);
    }
    ll ans = 0;
    for(int i=0; i<e; i++) {
        int sz = arr[i].size();
        vl dp1(sz, 0), dp2(sz, 0);
        for(int j=0; j<sz; j++) {
            if(arr[i][j] != 1)
                continue;
            if(j > 0)
                dp1[j] = dp1[j - 1];
            dp1[j]++;
        }
        for(int j=sz-1; j>=0; j--) {
            if(arr[i][j] != 1)
                continue;
            if(j != sz - 1)
                dp2[j] = dp2[j + 1];
            dp2[j]++;
        }
        for(int j=1; j<sz; j++) {
            if(prime[arr[i][j]])
                ans += dp1[j - 1];
        }
        for(int j=sz-2; j>=0; j--) {
            if(prime[arr[i][j]])
                ans += dp2[j + 1];
        }
        for(int j=1; j<sz-1; j++) {
            if(prime[arr[i][j]]
            && dp1[j - 1] && dp2[j + 1]) {
                ans -= dp1[j - 1] + dp2[j + 1];
                ans += (dp1[j - 1] + 1) * (dp2[j + 1] + 1) - 1;
            }
        }
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