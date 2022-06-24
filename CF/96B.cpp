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
    int n; cin>>n;
    vl arr;
    for(int i=0; i<(1 << 11); i++) {
        string str_rep;
        auto cpy = i;
        int cnt4 = 0;
        do {
            str_rep.push_back((cpy & 1 ? '4' : '7'));
            if(cpy & 1) cnt4++;
            cpy >>= 1;
        } while(cpy);
        auto num = stoll(str_rep);
        if(num >= n && (str_rep.length() % 2) == 0 && (cnt4 == (int)str_rep.length() / 2)) {
            arr.push_back(num);
        }
    }
    for(int i=0; i<(1 << 11); i++) {
        string str_rep;
        auto cpy = i;
        int cnt4 = 0;
        do {
            str_rep.push_back((cpy & 1 ? '7' : '4'));
            if(cpy & 1) cnt4++;
            cpy >>= 1;
        } while(cpy);
        auto num = stoll(str_rep);
        if(num >= n && (str_rep.length() % 2) == 0 && (cnt4 == (int)str_rep.length() / 2)) {
            arr.push_back(num);
        }
    }
    sort(arr.begin(), arr.end());
    cout<<arr.front()<<"\n";
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