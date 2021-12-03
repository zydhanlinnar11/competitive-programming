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
    vector<pii> a(n), b(n), c(n), d(n), e(n);
    vector<vi> arr(n, vi(5));
    for(int i=0; i<n; i++) {
        cin>>a[i].first>>b[i].first>>c[i].first>>d[i].first>>e[i].first;
        arr[i][0] = a[i].first;
        arr[i][1] = b[i].first;
        arr[i][2] = c[i].first;
        arr[i][3] = d[i].first;
        arr[i][4] = e[i].first;
        a[i].second = i;
        b[i].second = i;
        c[i].second = i;
        d[i].second = i;
        e[i].second = i;
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());
    sort(d.rbegin(), d.rend());
    sort(e.rbegin(), e.rend());
    set<int> strong;
    for(int i=0; i<n; i++) {
        if(strong.size() >= 450) break;
        strong.insert(a[i].second);
        strong.insert(b[i].second);
        strong.insert(c[i].second);
        strong.insert(d[i].second);
        strong.insert(e[i].second);
    }
    vi st;
    for(int i: strong) st.push_back(i);
    int ans = INT_MIN;
    for(int i=0; i<(int)st.size() - 2; i++) {
        for(int j=i+1; j<(int)st.size(); j++) {
            for(int k=j+1; k<(int)st.size(); k++) {
                vi tmp(5);
                for(int l=0; l<5; l++)
                    tmp[l] = max(arr[st[i]][l], max(arr[st[j]][l], arr[st[k]][l]));
                ans = max(ans, *min_element(tmp.begin(), tmp.end()));
            }
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
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}