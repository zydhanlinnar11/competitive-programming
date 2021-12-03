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
typedef tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void prog() {
    int n;
    cin>>n;
    vector<pii> arr(n + 1);
    vi dp(n + 1, 0), dp2(n + 2, 0);
    // map<int, int> mp1, mp2;
    // set<pii> ms, ms2;
    set<pii> ttp, ttp2;
    for(int i=1; i<=n; i++) cin>>arr[i].first>>arr[i].second;
    for(int i=n; i>=1; i--) {
        dp2[i] = dp2[i + 1];
        bool masuk = (dp2[i + 1] <= arr[i].first);
        dp2[i] += masuk;
        pii now = mp(arr[i].second, arr[i].first);
        bool ganti = dp2[i + 1] == arr[i].first + 1 && now > *ttp2.begin();
        if(ganti || masuk)
            ttp2.insert(now);
        else if(ganti)
            ttp2.erase(ttp2.begin());
        // if(i > 1 && dp2[i] != dp2[i + 1])
        //     ms2.insert(mp(arr[i].second, mp2[arr[i].second]++));
    }
    int ans = 0;
    for(int i=1; i<=n; i++) {
        auto f2 = ttp2.find(mp(arr[i].second, arr[i].first));
        if(f2 != ttp2.end()) ttp2.erase(f2);

        dp[i] = dp[i - 1];
        bool masuk = (dp[i - 1] <= arr[i].second);
        dp[i] += masuk;
        bool ganti = dp[i - 1] == arr[i].second + 1 && arr[i] > *ttp.begin();
        if(ganti || masuk)
            ttp.insert(arr[i]);
        if(ganti)
            ttp.erase(ttp.begin());
        // int erased = ttp2.order_of_key(mp(dp[i], -1));
        int erased = distance(ttp2.begin(), ttp2.find(mp(dp[i], -1)));
        ans = max(ans, (int)ttp.size() + (int)ttp2.size() - erased);
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
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}