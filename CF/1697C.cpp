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
typedef vector<ll> vl;
typedef vector<vl> vl2d;
typedef vector<string> vs;
typedef vector<vs> vs2d;
typedef vector<pii> vii;
typedef vector<pll> vll;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void prog() {
    int n;
    cin>>n;
    string s, t;
    cin>>s>>t;
    vector<set<int>> idx(3);
    for(int i=0; i<n; i++) {
        idx[s[i] - 'a'].insert(i);
    }
    for(int i=0; i<n - 1; i++) {
        if(s[i] == t[i]) continue;
        if(s[i] != t[i] - 1) {
            cout<<"NO\n";
            return;
        }
        auto next = idx[s[i] - 'a' + 1].lower_bound(i + 1);
        if(next == idx[s[i] - 'a' + 1].end()) {
            cout<<"NO\n";
            return;
        }
        auto nextVal = *next;
        auto exclude = (s[i] - 'a' + 2) % 3;
        bool exist = idx[exclude].lower_bound(i + 1) != idx[exclude].upper_bound(nextVal - 1);
        if(exist) {
            cout<<"NO\n";
            return;
        }
        idx[s[i] - 'a'].erase(i);
        idx[s[i] - 'a'].insert(nextVal);
        idx[s[i] - 'a' + 1].erase(nextVal);
        idx[s[i] - 'a' + 1].insert(i);
        swap(s[i], s[nextVal]);
    }
    cout<<(s == t ? "YES\n" : "NO\n");
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