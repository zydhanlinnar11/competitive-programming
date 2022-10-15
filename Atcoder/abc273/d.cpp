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
    int h, w, rs, cs;
    cin>>h>>w>>rs>>cs;
    map<int, set<int>> colByRow, rowByCol;
    map<int, set<int>> colByRowNeg, rowByColNeg;
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        int ri, ci;
        cin>>ri>>ci;
        colByRow[ri].insert(ci);
        rowByCol[ci].insert(ri);
        colByRowNeg[ri].insert(-ci);
        rowByColNeg[ci].insert(-ri);
    }
    int q; cin>>q;
    while(q--) {
        char d; int l;
        cin>>d>>l;
        if(d == 'U') {
            auto &arr = rowByColNeg[cs];
            auto nextWall = arr.upper_bound(-rs);
            auto maxDown = nextWall == arr.end() ? 1 : -(*nextWall) + 1;
            rs = max(rs - l, maxDown);
        } else if(d == 'R') {
            auto &arr = colByRow[rs];
            auto nextWall = arr.upper_bound(cs);
            auto maxRight = nextWall == arr.end() ? w : (*nextWall) - 1;
            cs = min(cs + l, maxRight);
        } else if(d == 'L') {
            auto &arr = colByRowNeg[rs];
            auto nextWall = arr.upper_bound(-cs);
            auto maxLeft = nextWall == arr.end() ? 1 : -(*nextWall) + 1;
            cs = max(cs - l, maxLeft);
        } else if(d == 'D') {
            auto &arr = rowByCol[cs];
            auto nextWall = arr.upper_bound(rs);
            auto maxUp = nextWall == arr.end() ? h : (*nextWall) - 1;
            rs = min(rs + l, maxUp);
        }
        cout<<rs<<" "<<cs<<"\n";
    }
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/Atcoder/abc273/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/Atcoder/abc273/out", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}