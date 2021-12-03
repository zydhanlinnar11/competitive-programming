#include <vector>
#include <iostream>
#define mp(x, y) make_pair(x, y)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vi> vi2d;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void prog() {
    int n, m;
    cin>>n>>m;
    vector<string> grid(n + 1, string());
    vector<vector<pii>> ans(2);
    for(int i=1; i<=n; i++) {
        grid[i].resize(m + 1);
        for(int j=1; j<=m; j++) {
            if((i + j + (i - 1) / 2) % 2 == 0) grid[i][j] = 'X', ans[0].push_back(mp(i, j));
            else grid[i][j] = 'O', ans[1].push_back(mp(i, j));
        }
    }
    int xitr=0, oitr=0;
    for(int i=0; i<n*m; i++) {
        char c;
        cin>>c;
        if(c == 'X') cout<<ans[0][xitr].first<<" "<<ans[0][xitr++].second<<endl;
        else cout<<ans[1][oitr].first<<" "<<ans[1][oitr++].second<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/CP/CF/in", "r", stdin);
    #endif
    int t = 1;
    // cin>>t;
    while(t--) prog();
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}