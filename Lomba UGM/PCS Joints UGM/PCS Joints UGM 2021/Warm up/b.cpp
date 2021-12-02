#include <bits/stdc++.h>
using namespace std;
map<string, map<string, bool>> dp;

int main() {
    int jmlSaklar, jmlLampu;
    cin>>jmlSaklar>>jmlLampu;
    int bitLampu = 0;
    for(int i=0; i<jmlLampu; i++)
        bitLampu |= 1 << i;
    dp["0"]["0"] = true;
    for(int i=0; i<jmlSaklar; i++) {
        int jmlDinyalain;
        cin>>jmlDinyalain;
        int bitDinyalain = 0;
        for(int j=0; j < jmlDinyalain; j++) {
            int tmp;
            cin>>tmp;
            bitDinyalain |= 1 << (tmp - 1);
        }
        dp[to_string(bitDinyalain)][bitDinyalain] = true;
    }

    // for(int i=1; i<=bitLampu; i++) {
    //     for(int j=0; j<=bitLampu; j++) {
    //         if(dp[i - 1][j])
    //             dp[i][j] = dp[i - 1][j];
    //         else if(dp[i - 1][j - 1] & dp[i - 1][j ^ (j - 1)])
    //             dp[i][j] = dp[i - 1][j - 1] & dp[i - 1][j ^ (j - 1)];
    //     }
    // }

    // for(int i=0; i<=bitLampu; i++) {
    //     for(int j=0; j<=bitLampu; j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }
    if(dp[bitLampu][bitLampu])
        cout<<"YA\n";
    else cout<<"TIDAK\n";
}