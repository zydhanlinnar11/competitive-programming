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
    deque<int> q, q2;
    set<pii> st;
    vi arr(n);
    for(int i=0; i<n; i++) {
        int tmp;
        cin>>tmp;
        arr[i] = tmp;
        if(!st.empty() && st.rbegin()->second >= tmp) {
            auto x = st.rbegin();
            x++;
            if(x != st.rend() && x->second < st.rbegin()->second)
                q.push_front(i - 1);
        }
        st.insert({i, tmp});
    }
    if(q.empty() && is_sorted(arr.rbegin(), arr.rend())) {
        cout<<"0\n";
        return;
    }
    q.push_front(n - 1);
    int hari = 1;
    while(true) {
        if(q.empty() && q2.empty())
            break;
        else if(q.empty())
            q = q2, q2.clear(), hari++;
        int curr = q.front();
        q.pop_front();
        auto ptr = st.lower_bound({curr, 0});
        if (ptr == st.end() || ptr->first != curr) 
            continue;
        while(ptr != st.begin()) {
            auto bef = ptr;
            bef--;
            if(bef->second >= ptr->second)
                break;
            auto tmp = ptr;
            ptr = bef;
            st.erase(tmp);
        }
        auto aft = ptr;
        aft++;
        if(aft != st.end() && ptr->second < aft->second) {
            q2.push_back(aft->first);
        }
    }
    cout<<hari<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/Hology/Hology 2022/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/Hology/Hology 2022/out", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}