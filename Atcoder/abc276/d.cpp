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
    int n;
    cin>>n;
    vi arr(n);
    for(auto &i: arr)
        cin>>i;
    sort(arr.begin(), arr.end());
    ll ans = INT64_MAX;
    vvi pangkat(2, vi(n));
    vi sisa(n);
    for(int i=0; i<n; i++) {
        auto x = arr[i];
        pangkat[0][i] = __builtin_ctz(x);
        x >>= pangkat[0][i];
        pangkat[1][i] = 0;
        while(x % 3 == 0)
            x /= 3, pangkat[1][i]++;
        sisa[i] = x;
    }
    for(int i=0; i<=pangkat[0][0]; i++) {
        for(int j=0; j<=pangkat[1][0]; j++) {
            int base3 = 1;
            for(int k=0; k<j; k++)
                base3 *= 3;
            int res = (1 << i) * base3 * sisa[0];
            bool can = true;
            ll cnt = 0;
            for(int k=0; k<n; k++) {
                if(pangkat[0][k] < i || pangkat[1][k] < j || (arr[k] % res) != 0) {
                    can = false;
                    break;
                }
                int rem = arr[k] / res;
                rem >>= __builtin_ctz(rem);
                while(rem % 3 == 0) rem /= 3;
                if(rem != 1) {
                    can = false;
                    break;
                }
                cnt += (pangkat[0][k] - i) + (pangkat[1][k] - j);
            }
            if(!can) continue;
            ans = min(ans, cnt);
        }
    }
    cout<<(ans == INT64_MAX ? -1 : ans)<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/Atcoder/abc276/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/Atcoder/abc276/out", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}