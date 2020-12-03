#include <bits/stdc++.h>
using namespace std;
#define MAX_CONST 50001
bool sudah[MAX_CONST] = {0};
int dp[MAX_CONST];
vector<int> coin;

int count(int kembali) {
    if(kembali < 0)
        return MAX_CONST;
    if(kembali == 0)
        return 0;
    if(sudah[kembali])
        return dp[kembali];
    int best = MAX_CONST;
    for(auto i : coin)
        best = min(best, count(kembali - i) + 1);
    sudah[kembali] = true;
    dp[kembali] = best;
    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, tmp, kembali;
    cin>>n;
    coin.resize(n);
    for(int i=0; i<n; i++) {
        cin>>tmp;
        coin[i] = tmp;
    }
    cin>>kembali;
    cout<<count(kembali)<<'\n';
    return 0;
}