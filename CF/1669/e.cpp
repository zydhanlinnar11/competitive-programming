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
typedef tree<char, null_type,less_equal<char>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void prog() {
    int n;
    cin>>n;
    map<int, pbds> s1, s2;
    map<int, map<char, int>> l1, l2;
    for(int i=0; i<n; i++) {
        string s;
        cin>>s;
        l1[s[0] - 'a'][s[1]]++;
        s1[s[0] - 'a'].insert(s[1]);
        l2[s[1] - 'a'][s[0]]++;
        s2[s[1] - 'a'].insert(s[0]);
    }
    ll ans = 0;
    for(auto &i: l1) {
        for(auto j: i.second) {
            ll tmp = s1[i.first].order_of_key(j.first) * j.second;
            ans += tmp;
        }
    }
    for(auto &i: l2) {
        for(auto j: i.second) {
            ll tmp = s2[i.first].order_of_key(j.first) * j.second;
            ans += tmp;
        }
    }
    cout<<ans<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/CF/1669/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/CF/1669/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}