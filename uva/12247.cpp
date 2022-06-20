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
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vll2d;
typedef vector<string> vs;
typedef vector<vs> vs2d;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}
set<int> all_cards;

inline int ub(int num) {
    auto res = all_cards.upper_bound(num);
    return res == all_cards.end() ? -1 : * res;
}

inline void prog() {
    vi cards(5);
    for(int &card: cards) cin>>card;
    if(*min_element(cards.begin(), cards.end()) ==
        *max_element(cards.begin(), cards.end()))
        exit(0);
    sort(cards.begin(), cards.begin() + 3);
    sort(cards.begin() + 3, cards.end());
    for(int i=1; i<=52; i++) all_cards.insert(i);
    for(int &card: cards) all_cards.erase(card);
    if(cards[3] > cards[2]) cout<<*all_cards.begin()<<"\n";
    else if(cards[4] > cards[2] && cards[3] > cards[1]) cout<<ub(cards[1])<<"\n";
    else if(cards[4] > cards[2]) cout<<ub(cards[2])<<"\n";
    else if(cards[3] > cards[1]) cout<<ub(cards[1])<<"\n";
    else cout<<"-1\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/uva/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/uva/out", "w", stdout);
    #endif
    // int t = 1;
    // cin>>t;
    while(true) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}