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
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vi2d;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vl2d;
typedef vector<string> vs;
typedef vector<vs> vs2d;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<pll> vll;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void prog() {
    int n; cin>>n;
    viii segments(n);
    for(int i=0; i<n; i++) {
        cin>>segments[i].first.first>>segments[i].first.second;
        segments[i].first.first--, segments[i].first.second--;
        segments[i].second = i;
    }
    sort(segments.begin(), segments.end(), [](piii a, piii b) {
        if(a.first.first == b.first.first) return a.first.second > b.first.second;
        return a.first.first < b.first.first;
    });
    int curr = -1, idx = 0;
    priority_queue<pii, vector<pii>, greater<pii>> nonIntersects;
    vi ans(n);
    for(int i=0; i<n; i++) {
        auto &segment = segments[i];
        auto &[coord, ii] = segment;
        auto &[l, r] = coord;
        ans[ii] = idx;
        if(r <= curr) continue;
        if(l <= curr) {
            auto fnd = nonIntersects.top();
            nonIntersects.pop();
            nonIntersects.push({fnd.first, r});
            curr = r;
            continue;
        }
        ans[ii] = ++idx;
        curr = r;
        nonIntersects.push({l, r});
    }
    if(nonIntersects.size() < 2) {
        cout<<"-1\n";
        return;
    } 
    for(int i=0; i<n; i++)
        cout<<(ans[i] % 2) + 1<<" \n"[i == n - 1]; 
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