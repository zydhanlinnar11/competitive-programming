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
    string s, t;
    cin>>s>>t;
    int n = s.length();
    int cnt = 1;
    char tmp = s[0];
    vector<pair<char, int>> p1, p2;
    for(int i=1; i<=n; i++) {
        if(tmp != s[i] || i == n) {
            p1.push_back({tmp, cnt});
            tmp = s[i];
            cnt = 1;
            continue;
        }
        cnt++;
    }
    tmp = t[0];
    for(int i=1; i<=(int)t.length(); i++) {
        if(tmp != t[i] || i == (int)t.length()) {
            p2.push_back({tmp, cnt});
            tmp = t[i];
            cnt = 1;
            continue;
        }
        cnt++;
    }
    if(p1.size() != p2.size()) {
        cout<<"No\n";
        return;
    }
    for(int i=0; i<(int)p1.size(); i++) {
        if(p1[i].first != p2[i].first
            || (p1[i].second == 1 && p1[i].second < p2[i].second)
            || (p1[i].second > p2[i].second)) {
                cout<<"No\n";
                return;
            }
    }
    cout<<"Yes\n";

}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/Atcoder/abc259/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/Atcoder/abc259/out", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}