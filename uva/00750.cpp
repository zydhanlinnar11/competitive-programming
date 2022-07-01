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

inline void getSol(vi2d &ans, vi &row) {
    if(row.size() == 9U) {
        ans.push_back(row);
        return;
    }
    for(int i=1; i<=8; i++) {
        if(!canFit(row, i, row.size()))
            continue;
        row.push_back(i);
        getSol(ans, row);
        row.pop_back();
    }
}

vi2d ans;

inline void prog() {
    int a, b;
    cin>>a>>b;
    int cnt=1;
    for(auto &i: ans) {
        if(i[b] != a) continue;
        printf("%2d      ", cnt++);
        for(int j=1; j<=8; j++) {
            cout<<i[j]<<" \n"[j == 8];
        }
    }
}

int main() {
    chrono_time_start = system_clock::now();
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    vi row = {0}; 
    for(int i=1; i<=8; i++) {
        row.push_back(i);
        getSol(ans, row);
        row.pop_back();
    }
    sort(ans.begin(), ans.end());
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/uva/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/uva/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) {
        cout<<"SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";
        prog();
        if(t) cout<<"\n";
    }
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}