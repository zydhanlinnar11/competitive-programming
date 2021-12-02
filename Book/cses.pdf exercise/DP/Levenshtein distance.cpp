#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2;
    cin>>s1>>s2;
    int dp[s1.length() + 1][s2.length() + 1];
    for(int i=0; i <= s1.length(); i++)
        dp[i][0] = i;
    for(int i=0; i <= s2.length(); i++)
        dp[0][i] = i;
    for(int i=1; i<=s1.length(); i++)
        for(int j=1; j <= s2.length(); j++) {
            dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1),
                        dp[i - 1][j - 1] + ((s1[i - 1] != s2[ j - 1]) ? 1 : 0));
        }
    cout<<"Minimum edit to make "+s1+" to "+s2+" is "<<dp[s1.length()][s2.length()]<<'\n';
}