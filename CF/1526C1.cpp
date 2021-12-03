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

inline void prog() {
    int n, ans = 0;
    cin>>n;
    vector<ll> arr(n + 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));
    for(int i=1; i<=n; i++) {
        cin>>arr[i];
        dp[i][1] = arr[i];
    }
    dp[0][0] = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j]);
            if(dp[i - 1][j - 1] >= 0 && dp[i - 1][j - 1] + arr[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + arr[i]);
            if(dp[i][j] >= 0) ans = max(ans, j);
        }
    }
    cout<<ans<<"\n";
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