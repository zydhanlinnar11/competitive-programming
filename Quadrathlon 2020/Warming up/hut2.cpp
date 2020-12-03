#include <bits/stdc++.h>
using namespace std;

int CountPS(string str, int n) {
    int dp[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dp[i][j] = 0;

    bool P[n][n]; 
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            P[i][j] = 0;

    for (int i= 0; i< n; i++) 
        P[i][i] = true; 

    for (int i=0; i<n-1; i++)  { 
        if (str[i] == str[i+1]) { 
            P[i][i+1] = true; 
            dp[i][i+1] = 1 ; 
        } 
    } 

    for (int gap=2 ; gap<n; gap++){
        for (int i=0; i<n-gap; i++) { 
            int j = gap + i; 
  
            if (str[i] == str[j] && P[i+1][j-1] ) 
                P[i][j] = true; 

            if (P[i][j] == true) 
                dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1 - dp[i+1][j-1]; 
            else
                dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]; 
        } 
    } 

    return dp[0][n-1]; 
}

void func() {
    int k;
    string s;
    cin>>s>>k;
    int len = s.length();
    cout<<max(0, k - CountPS(s, len) - len)<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    short t;
    cin>>t;
    while(t--) // ngeloop testcase
        func();
    return 0;
}