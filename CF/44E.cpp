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
    int k, a, b;
    cin>>k>>a>>b;
    string s;
    cin>>s;
    vvi dp(k+1, vi(201, false));
    dp[0][0] = true;
    for(int i=1; i<=k; i++) {
        for(int j=0; j<=200; j++) {
            for(int kk=a; kk<=b; kk++) {
                if(kk > j)
                    continue;
                dp[i][j] |= dp[i - 1][j - kk];
            }
        }
    }
    if(!dp[k][s.length()]) {
        cout<<"No solution\n";
        return;
    }
    int len = s.length();
    int idx = 0;
    k--;
    while(len) {
        for(int i=a; i<=b; i++) {
            if(dp[k][len - i]) {
                k--;
                len -= i;
                cout<<s.substr(idx, i)<<"\n";
                idx += i;
                break;
            }
        }
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