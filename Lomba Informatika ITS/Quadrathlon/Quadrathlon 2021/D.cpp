#pragma GCC optimize("trapv")
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

inline __uint128_t modmul(__uint128_t a, __uint128_t b, __uint128_t mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

int lis(string str, int n)
{
    int pre[n], post[n];
 
    memset(pre, 0, sizeof(pre));
    memset(post, 0, sizeof(post));
 
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            pre[i] += pre[i - 1];
        }
 
        if (str[i] == '0') {
            pre[i] += 1;
        }
    }
 
    for (int i = n - 1; i >= 0; i--) {
 
        if (i != n - 1)
            post[i] += post[i + 1];
 
        if (str[i] == '1')
            post[i] += 1;
    }
 
    int ans = 0;
 
    for (int i = 0; i < n; i++) {
        ans = max(ans, pre[i] + post[i]);
    }
 
    return ans;
}

inline void prog() {
    ull n, k;
    cin>>n>>k;
    // assert(n >= 2 && n <= 100000);
    // assert(k >= 1 && k <= 1000000000000000000);
    string s;
    vi cnt(2, 0);
    cin>>s;
    for(unsigned i=0; i<n; i++) {
        cnt[s[i] - '0']++;
    }
    __uint128_t ans = max((__uint128_t)cnt[1] * k, (__uint128_t)lis(s, n) + cnt[0] * (k - 1));
    ans = max(ans, (__uint128_t)lis(s, n) + cnt[1] * (k - 1));
    assert((ans % MOD) <= UINT64_MAX && (ans % MOD) >= 0U);
    assert((ans % MOD) <= MOD && (ans % MOD) >= 0U);
    cout<<(ull)(ans % MOD)<<"\n";
    // for(int i=0; i<k; i++) tmp += s;
    // cout<<lis(tmp, n * k)<<"\n";
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