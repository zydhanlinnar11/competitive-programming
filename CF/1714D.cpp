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
    string s;
    cin>>s;
    int n;
    cin>>n;
    set<string> st;
    map<string, int> idx;
    for(int i=0; i<n; i++) {
        string tmp;
        cin>>tmp;
        st.insert(tmp);
        idx[tmp] = i;
    }
    vi dp(s.length()+1, INT_MAX);
    vi par(s.length()+1, 0);
    vi uses(s.length()+1, 0);
    dp[0] = 0;
    for(int i=1; i<=(int)s.length(); i++) {
        string tmp;
        for(int j=0; j<i; j++)
            tmp += s[j];
        for(int j=0; j<i; j++, tmp = tmp.substr(1, tmp.size() - 1)) {
            if(st.find(tmp) == st.end())
                continue;
            if(dp[i - tmp.length()] == INT_MAX)
                continue;
            if(dp[i - tmp.length()] + 1 >= dp[i])
                continue;
            dp[i] = dp[i - tmp.length()] + 1;
            par[i] = i - tmp.length();
            uses[i] = idx[tmp];
            for(auto k=i-1; k>=0; k--) {
                if(dp[k] < dp[i])
                    continue;
                dp[k] = dp[i], par[k] = i;
            }
        }
    }
    cout<<(dp.back() == INT_MAX ? -1 : dp.back())<<"\n";
    if(dp.back() == INT_MAX)
        return;
    int curr = s.length();
    for(int i=0; i<dp.back(); i++) {
        if(par[curr] >= curr) {
            i--;
            curr = par[curr];
            continue;
        }
        cout<<uses[curr] + 1<<" "<<par[curr] + 1<<"\n";
        curr = par[curr];
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
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}