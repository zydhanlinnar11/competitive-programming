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

inline bool canFit(vi &row, int r, int c) {
    for(int prevCol=1; prevCol<c; prevCol++) {
        if(row[prevCol] == r
         || abs(r - row[prevCol]) == abs(c - prevCol))
         return false;
    }
    return true;
}

inline void getSol(vi2d &grid, int &ans, vi &row) {
    if(row.size() == 9U) {
        int loc_ans = 0;
        for(int i=1; i<=8; i++) {
            loc_ans += grid[row[i] - 1][i - 1];
        }
        ans = max(ans, loc_ans);
        return;
    }
    for(int i=1; i<=8; i++) {
        if(!canFit(row, i, row.size()))
            continue;
        row.push_back(i);
        getSol(grid, ans, row);
        row.pop_back();
    }
}

inline void prog() {
    vi row = {0}; int ans = 0; vi2d grid(8, vi(8));
    for(auto &i: grid) {
        for(auto &j: i) {
            cin>>j;
        }
    }
    for(int i=1; i<=8; i++) {
        row.push_back(i);
        getSol(grid, ans, row);
        row.pop_back();
    }
    printf("%5d\n", ans);
}

int main() {
    chrono_time_start = system_clock::now();
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/uva/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/uva/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) {
        prog();
    }
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}