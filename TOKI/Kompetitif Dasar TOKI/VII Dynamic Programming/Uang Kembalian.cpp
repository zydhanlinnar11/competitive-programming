#include <bits/stdc++.h>
using namespace std;
bool filled[500] = {0}, exist = false;
int dp[500] = {0}, n, k, coin[500];

int tukar(int x) {
    if(x == 0) {
        exist = true;
        return 0;
    }
    if(filled[x]) return dp[x];
    int min = INT_MAX;
    bool subexist = false;
    for(int i=0; i<n; i++) {
        if(coin[i] <= x) {
            subexist = true;
            int tmp = 1 + tukar(x - coin[i]);
            min = (tmp < min && tmp != -1) ? tmp : min;
        } else if(i == (n - 1) && !subexist) {
            filled[x] = true;
            dp[x] = -1;
            return -1;
        }
    }
    filled[x] = true;
    dp[x] = min;
    return min;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>coin[i];
    cin>>k;
    int val = tukar(k);
    cout<<((exist) ? (val) : (-1))<<'\n';
    return 0;
}