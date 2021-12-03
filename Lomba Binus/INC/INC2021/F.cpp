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

inline bool isPalindrome(string &s, int st, int en) {
    for(int i=st; i<=(st + en) / 2; i++) {
        if(s[i] != s[en - (i - st)]) return false;
    }
    return true;
}

inline void prog() {
    string s;
    cin>>s;
    for(unsigned i=0; i<s.length()-1; i++) {
        if(isPalindrome(s, 0, i) && isPalindrome(s, i+1, (int)s.length()-1)) {
            for(unsigned j=0; j<=i; j++) cout<<s[j];
            cout<<" ";
            for(unsigned j=i+1; j<s.length(); j++) cout<<s[j];
            cout<<"\n";
            return;
        }
    }
    cout<<"NO\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/CP/CF/in", "r", stdin);
    #endif
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}