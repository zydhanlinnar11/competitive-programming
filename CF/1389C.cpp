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

vs goods;

inline void prog() {
    string s;
    cin>>s;
    int n = s.length();
    vvi indices(10);
    for(int i=0; i<n; i++)
        indices[s[i] - '0'].push_back(i);
    int ans = n - 2;
    for(auto &good: goods) {
        int g0 = good[0] - '0';
        int g1 = good[1] - '0';
        auto &ig0 = indices[g0];
        auto &ig1 = indices[g1];
        if(g0 == g1) {
            ans = min(ans, n - (int)ig0.size());
            continue;
        }
        if(ig0.empty())
            continue;
        int cnt = 0;
        for(int i=0; i<(int)ig0.size()-1; i++) {
            int tmp = lower_bound(ig1.begin(), ig1.end(), ig0[i + 1]) - upper_bound(ig1.begin(), ig1.end(), ig0[i]);
            if(tmp) cnt += 2;
        }
        if(upper_bound(ig1.begin(), ig1.end(), ig0.back()) != ig1.end()
            || (!ig1.empty() && ig1.front() < ig0.front()))
                cnt += 2;
        ans = min(ans, n - cnt);
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
    for(char i='0'; i<='9'; i++)
        for(char j='0'; j<='9'; j++)
            goods.push_back(string() + i + j);
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}