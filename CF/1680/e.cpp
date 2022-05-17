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

inline void prog() {
    int n;
    cin>>n;
    vs arr(2);
    cin>>arr[0]>>arr[1];
    vi cnt(2);
    vi2d dp(2, vi(2));
    dp[0][0] = dp[1][0] = INT_MAX;
    dp[0][1] = dp[1][1] = INT_MIN;
    for(int i=0; i<2; i++)
        for(int j=0; j<n; j++) {
            cnt[i] += arr[i][j] == '*';
            if(arr[i][j] == '.') continue;
            dp[i][0] = min(dp[i][0], j); 
            dp[i][1] = max(dp[i][1], j); 
        }

    int ans = INT_MAX;
    for(int i=0; i<2; i++) {
        for(int j=0; j<n; j++) {
            int sc = 0;
            int lwn = i == 0 ? 1 : 0;
            if(dp[i][0] < j) sc += j - dp[i][0];
            if(dp[i][1] > j) sc += dp[i][1] - j;
            if(dp[lwn][0] < j) sc += j - dp[lwn][0] + 1;
            if(dp[lwn][1] > j) sc += dp[lwn][1] - j + 1;
            if(dp[lwn][0] < j && dp[lwn][1] > j) sc--;
            ans = min(ans, sc);
            if(ans == 1)
                return;
        }
    }
    cout<<ans<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/CF/1680/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/CF/1680/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}