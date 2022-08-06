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

inline void prog() {
    vi arr;
    while(true) {
        int x; char c;
        if(scanf("%d%c", &x, &c) == EOF)
            exit(0);
        arr.push_back(x);
        if(c == '\n')
            break;
    }
    bitset<2000> can(0);
    int n = arr.size();
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++) {
            int diff = abs(arr[i] - arr[j]);
            if(can[diff]) {
                printf("not a ruler\n");
                return;
            }
            can[diff] = true;
        }
    int mx = *max_element(arr.begin(), arr.end());
    vi missing;
    for(int i=1; i<=mx; i++)
        if(!can[i]) missing.push_back(i);
    if(missing.empty())
        printf("perfect\n");
    else {
        printf("missing");
        for(auto &i: missing)
            printf(" %d", i);
        printf("\n");
    }
}

int main() {
    chrono_time_start = system_clock::now();
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/kattis/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/kattis/out", "w", stdout);
    #endif
    // int t = 1;
    // cin>>t;
    while(true) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}