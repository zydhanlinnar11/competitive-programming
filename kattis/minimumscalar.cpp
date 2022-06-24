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

inline ll prog() {
    int n; cin>>n;
    deque<ll> dq1, dq2;
    for(int i=0; i<n; i++) {
        int tmp; cin>>tmp; dq1.push_back(tmp);
    }
    for(int i=0; i<n; i++) {
        int tmp; cin>>tmp; dq2.push_back(tmp);
    }
    sort(dq1.begin(), dq1.end());
    sort(dq2.begin(), dq2.end());
    ll ans = 0;
    while(!dq1.empty()) {
        ans += dq1.front() * dq2.back();
        dq1.pop_front(); dq2.pop_back();
    }

    return ans;
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
    cin>>t;
    for(int i=1; i<=t; i++) {
        printf("Case #%d: %lld\n", i, prog());
    }
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}