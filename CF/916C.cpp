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

bool isPrime(int n) {
    if(n <= 1)
        return false;
    if(n == 2)
        return true;
    for(int i=2; i*i<=n; i++)
        if(n % i == 0)
            return false;
    return true;
}

typedef tuple<int, int, int> piii;
typedef vector<piii> viii;

inline void prog() {
    int n, m;
    cin>>n>>m;
    int prime;
    for(int i=n-1; i<=200000; i++) {
        if(isPrime(i)) {
            prime = i;
            break;
        }
    }
    int sp = prime, mstw = prime;
    viii ans;
    for(int i=1; i<n; i++) {
        int w = (prime / (n - i)) + (prime % (n - i) != 0);
        ans.push_back({i, i + 1, w});
        prime -= w;
    }
    for(int i=1; i<=n && (int)ans.size() < m; i++) {
        for(int j=i+2; j<=n && (int)ans.size() < m; j++) {
            ans.push_back({i, j, 1000000000});
        }
    }
    cout<<sp<<" "<<mstw<<"\n";
    for(auto &[u, v, w]: ans) {
        cout<<u<<" "<<v<<" "<<w<<"\n";
    }
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
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}