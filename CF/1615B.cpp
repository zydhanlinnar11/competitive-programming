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
typedef vector<ll> vl;
typedef vector<vl> vl2d;
typedef vector<string> vs;
typedef vector<vs> vs2d;
typedef vector<pii> vii;
typedef vector<pll> vll;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline string toBinary32Bit(int n) {
    string res;
    while(n) {
        res.push_back('0' + (n % 2));
        n >>= 1;
    }
    return res + string(32U - res.length(), '0');
}

inline void prog(vi2d &prefSum) {
    int l, r;
    cin>>l>>r;
    int ans = r - l + 1;
    for(int i=0; i<32; i++) {
        auto zeroCount = prefSum.at(r).at(i) - prefSum.at(l - 1).at(i);
        ans = min(ans, zeroCount);
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
    vs bits;
    vi2d prefSum(2e5+1, vi(32, 0));
    for(int i=0; i<=2e5; i++)
        bits.push_back(toBinary32Bit(i));
    
    for(int i=0; i<32; i++) {
        int zeroCount = 0;
        for(unsigned j=0; j<bits.size(); j++) {
            zeroCount += (bits[j][i] == '0');
            prefSum.at(j).at(i) = zeroCount;
        }
    }
    int t = 1;
    cin>>t;
    while(t--) prog(prefSum);
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}