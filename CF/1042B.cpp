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

inline void prog() {
    int n;
    cin>>n;
    int ans = INT_MAX;
    map<string, int> mp;
    mp["A"] = INT_MAX;
    mp["B"] = INT_MAX;
    mp["C"] = INT_MAX;
    mp["AB"] = INT_MAX;
    mp["AC"] = INT_MAX;
    mp["BC"] = INT_MAX;
    mp["ABC"] = INT_MAX;
    vector<string> xx;
    for(auto i: mp) xx.push_back(i.first);
    // vector<pair<int, string>> a, b, c;
    for(int i=0; i<n; i++) {
        int x;
        string s;
        cin>>x>>s;
        sort(s.begin(), s.end());
        mp[s] = min(mp[s], x);
    }
    for(int i=0; i<xx.size() - 2; i++) {
        for(int j=i+1; j<xx.size() - 1; j++) {
            for(int k=j+1; k<xx.size(); k++) {
                string gg = xx[i]+xx[j]+xx[k];
                // if(gg == "ABC") cout<<"sip";
                if(gg.find('A') == -1 || gg.find('B') == -1 || gg.find('C') == -1)
                    continue;
                ans = min((ll)mp[xx[i]] + mp[xx[j]] + mp[xx[k]], (ll)ans);
            }
        }
    }
    for(int i=0; i<xx.size() - 1; i++) {
        for(int j=i+1; j<xx.size(); j++) {
            string gg = xx[i]+xx[j];
            // if(gg == "ABC") cout<<"sip";
            if(gg.find('A') == -1 || gg.find('B') == -1 || gg.find('C') == -1)
                continue;
            ans = min((ll)mp[xx[i]] + mp[xx[j]], (ll)ans);
        }
    }
    for(int i=0; i<xx.size(); i++) {
            string gg = xx[i];
            // if(gg == "ABC") cout<<"sip";
            if(gg.find('A') == -1 || gg.find('B') == -1 || gg.find('C') == -1)
                continue;
            ans = min((ll)mp[xx[i]], (ll)ans);
    }
    cout<<(ans == INT_MAX ? -1 : ans)<<'\n';
    // cout<<min(mp["A"]+mp["B"]+mp["C"], min(mp["A"]+mp["B"]+mp["C"]))
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