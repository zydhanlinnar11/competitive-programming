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

int getLength(ull n) {
    int len = 0;
    while(n) {
        len++;
        n /= 10;
    }
    return len;
}

inline void prog() {
    int n;
    ull x;
    cin>>n>>x;
    queue<pair<int, ull>> q;
    q.push({0, x});
    map<ull, int> dist;
    dist[x] = 0;
    while(!q.empty()) {
        auto [l, u] = q.front();
        q.pop();
        int lenu = getLength(u);
        if(lenu == n) {
            cout<<l<<"\n";
            return;
        }
        auto uCpy = u;
        for(;uCpy; uCpy /= 10) {
            auto mod = (uCpy % 10);
            if(mod == 0 || mod == 1)
                continue;
            auto v = mod * u;
            int lenv = getLength(v);
            if(lenv > n || (dist.find(v) != dist.end() && dist[v] <= l + 1))
                continue;
            dist[v] = l + 1;
            q.push({l + 1, v});
        }
    }
    cout<<"-1\n";
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
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}