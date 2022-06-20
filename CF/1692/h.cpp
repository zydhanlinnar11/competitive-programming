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

inline int getProfit(set<pii> &st, int l, int r) {
    int round = r - l + 1;
    return 2*st.rbegin()->first - round; 
}

inline void prog() {
    int n; cin>>n;
    vi arr(n);
    map<int, vi> indicesByVal;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        indicesByVal[arr[i]].push_back(i);
    }
    pair<pii, int> ans = {{0, 0}, 1};
    for(auto &[val, indices]: indicesByVal) {
        int loc_max = 1;
        int l = indices.front();
        for(int i=1; i<(int)indices.size(); i++) {
            loc_max = loc_max + 2 - (indices[i] - indices[i - 1]);
            if(ans.second < loc_max) {
                ans = {{l, indices[i]}, loc_max};
            } else if(loc_max <= 0) {
                loc_max = 1;
                l = indices[i];
            }
        }
    }
    auto &[l, r] = ans.first;
    cout<<arr[l]<<" "<<l + 1<<" "<<r + 1<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/CF/1692/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/CF/1692/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}