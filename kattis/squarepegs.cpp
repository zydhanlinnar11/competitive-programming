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
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<vl> vl2d;
typedef vector<pl> vll; 
typedef vector<string> vs;
typedef vector<vs> vs2d;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void prog() {
    int n, m, k; cin>>n>>m>>k;
    vi plots(n), circulars(m + k);
    for(auto &plot: plots) {
        cin>>plot;
        plot *= 4 * plot;
    }
    for(int i=0; i<m; i++) {
        cin>>circulars[i];
        circulars[i] *= 4 * circulars[i];
    }
    for(int i=0; i<k; i++) {
        cin>>circulars[i + m];
        circulars[i + m] *= 2 * circulars[i + m];
    }
    sort(plots.begin(), plots.end());
    sort(circulars.begin(), circulars.end());
    int ans = 0, i = 0, j = 0;
    while(i < (m + k) && j < n) {
        while(j < n && circulars[i] >= plots[j]) j++;
        if(j >= n) break;
        ++ans, ++i, ++j;
    }
    cout<<ans<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/kattis/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/kattis/out", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}