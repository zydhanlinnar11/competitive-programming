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
    int n, k; cin>>n>>k;
    map<int, int> count;
    for(int i=0; i<n; i++) {
        int tmp; cin>>tmp;
        count[tmp]++;
    }
    int lGlobal = -1, rGlobal = -1;
    int lLocal = -1, rLocal = -1;
    auto it = count.begin();
    for(; it != count.end(); it++) {
        if(it->second >= k) {
            lLocal = it->first;
            rLocal = it->first;
            it++;
            break;
        }
    }
    for(; it != count.end(); it++) {
        auto bef = it;
        bef--;
        if(bef->first == it->first - 1 && it->second >= k) {
            rLocal = it->first;
            continue;
        }
        if(rLocal - lLocal >= rGlobal - lGlobal) {
            rGlobal = rLocal;
            lGlobal = lLocal;
        }
        lLocal = -1;
        rLocal = -1;
        for(; it != count.end(); it++) {
            if(it->second >= k) {
                lLocal = it->first;
                rLocal = it->first;
                break;
            }
        }
        if(it == count.end()) break;
    }
    if((lLocal != -1 && rLocal != -1) && rLocal - lLocal >= rGlobal - lGlobal) {
        rGlobal = rLocal;
        lGlobal = lLocal;
    }
    if(lGlobal == -1 || rGlobal == -1) cout<<"-1\n";
    else cout<<lGlobal<<" "<<rGlobal<<"\n";
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