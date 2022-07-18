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

// topmost, ki, idx 
typedef tuple<int, int, int> piii;

inline void prog() {
    int n, k;
    cin>>n>>k;
    vvi stacked;
    set<piii> st;
    vi ans(n, -1);
    for(int i=0; i<n; i++) {
        int tmp;
        cin>>tmp;
        if(st.empty() || get<0>(*st.rbegin()) < tmp) {
            if(k == 1) {
                ans[tmp - 1] = i + 1;
                continue;
            }
            st.insert({tmp, 1, stacked.size()});
            stacked.push_back({tmp});
        } else {
            auto fnd = st.lower_bound({tmp, 0, 0});
            auto [topmost, ki, idx] = *fnd;
            st.erase(fnd);
            topmost = tmp;
            ki++;
            stacked[idx].push_back(tmp);
            if(ki == k) {
                auto &eatens = stacked[idx]; 
                for(auto &eaten: eatens) {
                    ans[eaten - 1] = i + 1;
                }
            } else {
                st.insert({topmost, ki, idx});
            }
        }
    }
    for(int i=0; i<n; i++) {
        cout<<ans[i]<<"\n";
    }
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/Atcoder/abc260/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/Atcoder/abc260/out", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}