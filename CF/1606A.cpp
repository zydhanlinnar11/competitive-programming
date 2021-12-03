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
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vi> vi2d;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

bool isSame(string &s) {
    vi cnt(2, 0);
    for(unsigned i=0; i<s.length() - 1; i++) {
        cnt[0] += s[i] == 'a' && s[i + 1] == 'b';
        cnt[1] += s[i] == 'b' && s[i + 1] == 'a';
    }
    return cnt[0] == cnt[1];
}

inline void prog() {
    string s;
    cin>>s;
    vector<string> arr(4, s);
    arr[0][0] = 'a';
    arr[1][s.length() - 1] = 'a';
    arr[2][0] = 'b';
    arr[3][s.length() - 1] = 'b';
    string ans = "";
    int mn = s.length();
    for(auto i: arr) {
        if(isSame(i)) {
            int diff = 0;
            for(unsigned j=0; j<s.length(); j++) {
                diff += s[j] != i[j];
            }
            if(diff < mn)
                mn = diff, ans = i;
        }
    }
    cout<<ans<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/CP/CF/in", "r", stdin);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}