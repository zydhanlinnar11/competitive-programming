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
    int n;
    cin>>n;
    vvl freq(2, vl(26, 0));
    freq[0][0] = freq[1][0] = 1;
    vl len(2, 1);
    for(int i=0; i<n; i++) {
        int op, k; string x;
        cin>>op>>k>>x;
        len[op - 1] += x.length() * k;
        for(auto &c: x) {
            freq[op - 1][c - 'a'] += k;
        }
        bool bisa = false;
        for(int j=0; j<26 && !bisa; j++) {
            if(freq[0][j] == 0)
                continue;
            for(int l=25; l>=0 && !bisa; l--) {
                if(freq[1][l] == 0)
                    continue;
                if(j < l || (j == l && len[0] == freq[0][j] && len[0] < len[1]))
                    bisa = true;
            }
        }
        cout<<(bisa ? "YES" : "NO")<<"\n";
    }
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/CF/1742/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/CF/1742/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}